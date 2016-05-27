//==================================================================================================
/*!
  @file

  Defines the as_simd metafunction for AVX2 like extensions

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_AS_SIMD_HPP_INCLUDED

#include <boost/simd/arch/x86/avx/as_simd.hpp>
#include <boost/simd/detail/dispatch/meta/is_natural.hpp>

namespace boost { namespace simd
{
  namespace ext
  {
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
