//==================================================================================================
/*!
  @file

  Defines the expected_cardinal metafunction

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_EXPECTED_CARDINAL_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_EXPECTED_CARDINAL_HPP_INCLUDED

#include <boost/simd/arch/limits.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd
{
  template<typename T> struct logical;

  namespace detail
  {
    /*!
      @ingroup group-detail
      @brief Expected cardinal of register

      Computes the cardinal a potential SIMD register containing elements of type @c Type on
      extension @c Extension.

      @tparam Type      Element type of the expected register
      @tparam Extension SIMD Extension tag
    **/
    template<typename Type, typename Extension>
    struct expected_cardinal : brigand::int_<limits<Extension>::bytes/sizeof(Type)>
    {};

    template<typename Type, typename Extension>
    struct expected_cardinal<logical<Type>> : expected_cardinal<Type,Extension>
    {};
  }
} }

#endif
