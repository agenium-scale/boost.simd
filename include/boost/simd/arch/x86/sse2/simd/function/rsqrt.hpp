//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_RSQRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_RSQRT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/refine_rsqrt.hpp>
#include <boost/simd/constant/inf.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( rsqrt_
                          , (typename A0)
                          , bs::sse2_
                          , bs::raw_tag
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE A0 operator() (raw_tag const&
                                    , const A0 & a0) const BOOST_NOEXCEPT
    {
      return _mm_cvtps_pd(_mm_rsqrt_ps(_mm_cvtpd_ps(a0))); //The maximum error for this approximation is 1.5e-12
    }
  };

   BOOST_DISPATCH_OVERLOAD ( rsqrt_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const A0 & a00) const BOOST_NOEXCEPT
    {

      A0 a0 = refine_rsqrt(a00, refine_rsqrt(a00, refine_rsqrt(a00, raw_(rsqrt)(a00))));
      #ifndef BOOST_SIMD_NO_INFINITIES
      a0 = if_zero_else(a00 == Inf<A0>(),a0);
      #endif
      return if_else(is_eqz(a00), Inf<A0>(), a0);
    }
  };
} } }

#endif

