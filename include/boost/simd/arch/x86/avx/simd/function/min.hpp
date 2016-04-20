//==================================================================================================
/**
  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_MIN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_MIN_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_unord.hpp>
#include <boost/predef/compiler.h>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( min_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          , bs::pack_<bd::double_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
  #if !defined(BOOST_SIMD_NO_NANS) && defined(BOOST_COMP_GNUC_AVAILABLE)
        // workaround for GCC bug #57057
        return if_else(is_unord(a0, a1), a1, A0(_mm256_min_pd(a0, a1)));
  #else
        return _mm256_min_pd(a0,a1);
  #endif
      }
   };

   BOOST_DISPATCH_OVERLOAD( min_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          , bs::pack_<bd::single_<A0>, bs::avx_>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
  #if !defined(BOOST_SIMD_NO_NANS) && defined(BOOST_COMP_GNUC_AVAILABLE)
        // workaround for GCC bug #57057
        return if_else(is_unord(a0, a1), a1, A0(_mm256_min_ps(a0, a1)));
  #else
        return _mm256_min_ps(a0,a1);
  #endif
      }
   };
} } }

#endif
