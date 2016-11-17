//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_REC_FAST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_REC_FAST_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/raw.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( rec_
                          , (typename A0)
                          , bs::sse2_
                          , bs::fast_tag
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(fast_tag const&, const A0 & a0) const BOOST_NOEXCEPT
    {
      A0 r = refine_rec(a0,refine_rec(a0, raw_(rec)(a0))); //The error for this approximation is circa 1.e-44
      r =  if_else(is_eqz(a0),
                   bitwise_or(a0, Inf<A0>()),
                   r
                  );
      #ifndef BOOST_SIMD_NO_INFINITIES
      r = if_else(is_inf(a0),
                  bitwise_and(a0, Zero<A0>()),
                  r
                 );
      #endif
      return r;
    }
  };
} } }

#endif
