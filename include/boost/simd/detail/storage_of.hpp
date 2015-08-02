//==================================================================================================
/*!
  @file

  Defines the SIMD storage meta-generator

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_STORAGE_OF_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_STORAGE_OF_HPP_INCLUDED

#include <boost/simd/sdk/as_simd.hpp>
#include <boost/simd/sdk/expected_cardinal.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <type_traits>
#include <array>

namespace boost { namespace simd { namespace detail
{
  // Status for emulated SIMD storage
  using emulated_status   = brigand::int_<-1>;

  // Status for native SIMD storage
  using native_status     = brigand::int_<+0>;

  // Status for aggregated SIMD storage
  using aggregated_status = brigand::int_<+1>;

  /*!
    @ingroup group-detail
    @brief SIMD storage status

    Determines how a given block of @c C elements of type @c T should fit in the
    hardware registers proposed by extension @c X.
  **/
  template< typename T, std::size_t C, typename X>
  struct storage_status : brigand::int_<   (expected_cardinal<T,X>::value!=C)
                                        * ( (expected_cardinal<T,X>::value<C) ? +1 : -1)
                                      >
  {};

  // Forcibly emualted SIMD register stays emulated
  template< typename T, std::size_t C>
  struct storage_status<T,C,simd_emulation_> : emulated_status
  {};

  /*!
    @ingroup  group-detail
    @brief    Storage type for SIMD data

    For a given couple @c Type x @c Cardinal, provides the type usbale for storing a block
    containing @c Cardinal elements of type @c Type in an optimized way.

    @tparam Type      Type of the stored elements
    @tparam Cardinal  Number of element stored
  **/
  template< typename Type, std::size_t Cardinal
          , typename SIMDFamily = BOOST_SIMD_DEFAULT_FAMILY
          , typename Status = typename storage_status<Type,Cardinal,SIMDFamily>::type
          , typename Enable = void
          >
  struct storage_of
  {};

  // If the cardinal requested is slower than the expected one,
  // then try to find a suitable storage in parent extension.
  template< typename Type, std::size_t Cardinal, typename SIMDFamily>
  struct  storage_of<Type,Cardinal,SIMDFamily,emulated_status>
        : storage_of<Type,Cardinal, typename limits<SIMDFamily>::parent>
  {};

  // If the cardinal requested is slower than the expected one and no extension fits,
  // then use an array of scalar.
  template< typename Type, std::size_t Cardinal>
  struct storage_of<Type,Cardinal,boost::simd::simd_,emulated_status>
  {
    using type = std::array<Type,Cardinal>;
  };

  // If we match cardinals, use as_simd for current Familly
  template< typename Type, std::size_t Cardinal, typename SIMDFamily>
  struct storage_of<Type,Cardinal,SIMDFamily,native_status>
  {
    using type = boost::simd::as_simd<Type,SIMDFamily>;
  };

  // IF we request more than needed, we aggregate smaller SIMD registers
  template< typename Type, std::size_t Cardinal, typename SIMDFamily>
  struct storage_of<Type,Cardinal,SIMDFamily,aggregated_status>
  {
    enum { expected = expected_cardinal<Type,SIMDFamily>::value };
    enum { size     = Cardinal / expected };

    using base = typename storage_of<Type,expected,SIMDFamily>::type;
    using type = std::array<base,size>;
  };
} } }

#endif
