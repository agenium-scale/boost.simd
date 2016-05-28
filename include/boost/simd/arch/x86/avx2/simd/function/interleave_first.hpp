//==================================================================================================
/**
  Copyright 2016 Numscale SAS
  Copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/slice_low.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/slide.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( interleave_first_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_<bd::ints8_<A0>, bs::avx_>
                          , bs::pack_<bd::ints8_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      auto x0 = slice_low(a0);
      auto y0 = slice_low(a1);

      return  combine ( interleave_first(x0,y0)
                      , interleave_first(slide<8>(x0), slide<8>(y0))
                      );
    }
  };

  BOOST_DISPATCH_OVERLOAD ( interleave_first_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_<bd::ints16_<A0>, bs::avx_>
                          , bs::pack_<bd::ints16_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      auto x0 = slice_low(a0);
      auto y0 = slice_low(a1);

      return  combine ( interleave_first(x0,y0)
                      , interleave_first(slide<4>(x0), slide<4>(y0))
                      );
    }
  };

  BOOST_DISPATCH_OVERLOAD ( interleave_first_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_<bd::ints32_<A0>, bs::avx_>
                          , bs::pack_<bd::ints32_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return  bitwise_cast<A0>( interleave_first( bitwise_cast<bd::as_floating_t<A0>>(a0)
                                                , bitwise_cast<bd::as_floating_t<A0>>(a1)
                                                )
                              );
    }
  };

  BOOST_DISPATCH_OVERLOAD ( interleave_first_
                          , (typename A0)
                          , bs::avx2_
                          , bs::pack_<bd::ints64_<A0>, bs::avx_>
                          , bs::pack_<bd::ints64_<A0>, bs::avx_>
                         )
  {
    BOOST_FORCEINLINE A0 operator()(const A0 & a0, const A0 & a1 ) const BOOST_NOEXCEPT
    {
      return  bitwise_cast<A0>( interleave_first( bitwise_cast<bd::as_floating_t<A0>>(a0)
                                                , bitwise_cast<bd::as_floating_t<A0>>(a1)
                                                )
                              );
    }
  };
} } }

#endif
