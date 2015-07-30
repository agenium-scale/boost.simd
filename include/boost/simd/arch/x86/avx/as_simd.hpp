//==================================================================================================
/*!
  @file

  Defines the as_simd metafunction for AVX like extensions

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_DETAIL_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_DETAIL_AS_SIMD_HPP_INCLUDED

#include <boost/simd/arch/common/simd/as_simd.hpp>
#include <boost/dispatch/meta/introspection/is_natural.hpp>

namespace boost { namespace simd
{
  template<typename T> struct logical;

  namespace ext
  {
    template<typename T>
    struct as_simd<logical<T>, boost::simd::avx_> : as_simd<T, boost::simd::avx_> {};

    template<> struct as_simd<float, boost::simd::avx_>
    {
      using type = __m256;
    };

    template<> struct as_simd<double, boost::simd::avx_>
    {
      using type = __m256d;
    };

    template<typename T>
    struct as_simd< T, boost::simd::avx_
                  , typename std::enable_if<boost::dispatch::is_natural<T>::value>::type
                  >
    {
      using type = __m256i;
    };
  }
} }

#endif
