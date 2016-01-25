//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_SPLIT_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_SPLIT_MULTIPLIES_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/interleave_first.hpp>
#include <boost/simd/function/simd/interleave_second.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( split_multiplies_
                          , (typename A0, typename A1)
                          , bs::sse4_1_
                          , bs::pack_<bd::int32_<A0>, bs::sse_>
                          , bs::pack_<bd::int32_<A0>, bs::sse_>
                          , bs::pack_<bd::int64_<A1>, bs::sse_>
                          , bs::pack_<bd::int64_<A1>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE void operator() ( const A0 & a0
                                      , const A0 & a1
                                      , A1 & a2
                                      , A1 & a3) const BOOST_NOEXCEPT
    {
      A1 lo = _mm_mul_epi32(a0, a1);
      A1 hi = _mm_mul_epi32(_mm_srli_si128(a0, 4), _mm_srli_si128(a1, 4));

      a2 = interleave_first(lo, hi);
      a3 = interleave_second(lo, hi);
    }
  };
} } }

#endif
