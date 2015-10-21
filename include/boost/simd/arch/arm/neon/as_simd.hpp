//==================================================================================================
/*!
  @file

  Defines the as_simd metafunction for NEON like extensions

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_ARM_NEON_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_ARM_NEON_AS_SIMD_HPP_INCLUDED

#include <boost/simd/arch/common/simd/as_simd.hpp>
#include <boost/dispatch/meta/is_natural.hpp>
#include <boost/dispatch/meta/sign_of.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd
{
  template<typename T> struct logical;

  namespace ext
  {
    template<> struct as_simd<float, boost::simd::neon_>    { using type = float32x4_t; };
    template<> struct as_simd<float, boost::simd::neon64_>  { using type = float32x2_t; };

#ifdef __aarch64__
    template<> struct as_simd<double, boost::simd::neon_>   { using type = float64x2_t; };
    template<> struct as_simd<double, boost::simd::neon64_> { using type = float64x1_t; };
#endif

    template<typename T>
    struct  as_simd<logical<T>, boost::simd::neon_>
          : as_simd< boost::dispatch::as_integer<T,unsigned>, boost::simd::neon_>
    {};

    template<typename T>
    struct as_simd<logical<T>, boost::simd::neon64_>
         : as_simd< typename dispatch::as_integer<T,unsigned>::type, boost::simd::neon64_>
    {};

#if !defined( __aarch64__ )
    // Regular NEON don't have double support, so supporting logical<double> by error is nasty.
    template<> struct as_simd<logical<double>, boost::simd::neon_>
    {
      using type = brigand::no_such_type_;
    };

    template<> struct as_simd<logical<double>, boost::simd::neon64_>
    {
      using type = brigand::no_such_type_;
    };
#endif

    template<typename T>
    struct as_simd< T, boost::simd::neon_
                  , typename std::enable_if<boost::dispatch::is_natural<T>::value>
                  >
    {
      using t2b = brigand::map< brigand::pair < brigand::list<brigand::int_<1>,signed>
                                              , int8x16_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<2>,signed>
                                              , int16x8_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<4>,signed>
                                              , int32x4_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<8>,signed>
                                              , int64x2_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<1>,unsigned>
                                              , uint8x16_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<2>,unsigned>
                                              , uint16x8_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<4>,unsigned>
                                              , uint32x4_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<8>,unsigned>
                                              , uint64x2_t
                                              >
                              >;

      using type = brigand::at< t2b
                              , brigand::list<brigand::int_<sizeof(T)>,boost::dispatch::sign_of<T>>
                              >;
    };

    template<typename T>
    struct as_simd< T, boost::simd::neon64_
                  , typename std::enable_if<boost::dispatch::is_natural<T>::value>
                  >
    {
      using t2b = brigand::map< brigand::pair < brigand::list<brigand::int_<1>,signed>
                                              , int8x8_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<2>,signed>
                                              , int16x4_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<4>,signed>
                                              , int32x2_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<8>,signed>
                                              , int64x1_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<1>,unsigned>
                                              , uint8x8_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<2>,unsigned>
                                              , uint16x4_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<4>,unsigned>
                                              , uint32x2_t
                                              >
                              , brigand::pair < brigand::list<brigand::int_<8>,unsigned>
                                              , uint64x1_t
                                              >
                              >;

      using type = brigand::at< t2b
                              , brigand::list<brigand::int_<sizeof(T)>,boost::dispatch::sign_of<T>>
                              >;
    };
  }
} }

#endif
