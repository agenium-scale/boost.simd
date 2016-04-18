//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/shrai.hpp>
#include <boost/simd/function/simd/split_multiplies.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/meta/upgrade.hpp>

/* No native groups for 64-bit SSE;
 * we use bit tricks instead of calling saturate. */

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;

  BOOST_DISPATCH_OVERLOAD ( minus_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return _mm_sub_pd(a0,a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( minus_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::ints16_<A0>, bs::sse_>
                          , bs::pack_<bd::ints16_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return _mm_sub_epi16(a0,a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( minus_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::ints8_<A0>, bs::sse_>
                          , bs::pack_<bd::ints8_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return _mm_sub_epi8(a0,a1);
    }
  };



} } }

#endif
