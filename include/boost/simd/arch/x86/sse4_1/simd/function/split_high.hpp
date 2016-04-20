//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_SPLIT_HIGH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_SPLIT_HIGH_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/dispatch/meta/upgrade.hpp>
#include <boost/dispatch/meta/cardinal_of.hpp>
#include <boost/simd/function/simd/slide.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( split_high_
                          , (typename A0)
                          , bs::sse4_1_
                          , bs::pack_<bd::int8_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE upgrade_t<A0> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      return _mm_cvtepi8_epi16(slide<bd::cardinal_of<A0>::value/2>(a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( split_high_
                          , (typename A0)
                          , bs::sse4_1_
                          , bs::pack_<bd::int16_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE upgrade_t<A0> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      return _mm_cvtepi16_epi32(slide<bd::cardinal_of<A0>::value/2>(a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( split_high_
                          , (typename A0)
                          , bs::sse4_1_
                          , bs::pack_<bd::int32_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE upgrade_t<A0> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      return _mm_cvtepi32_epi64(slide<bd::cardinal_of<A0>::value/2>(a0));
    }
  };
} } }

#endif
