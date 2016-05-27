//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_ANY_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_ANY_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( any_
                          , (typename A0)
                          , bs::sse4_1_
                          , bs::pack_<bd::integer_<A0>, bs::sse_>
                         )
  {
    using sA0 = bd::scalar_of_t<A0>;
    BOOST_FORCEINLINE logical<sA0> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      return !_mm_testz_si128(a0, Allbits<A0>());
    }
  };

  BOOST_DISPATCH_OVERLOAD ( any_
                          , (typename A0)
                          , bs::sse4_1_
                          , bs::pack_<bd::floating_<A0>, bs::sse_>
                         )
  {
    using sA0 = bd::scalar_of_t<A0>;
    BOOST_FORCEINLINE logical<sA0> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      using i_t = bd::as_integer_t<A0>;
      return bitwise_cast<logical<sA0>>(any(bitwise_cast<i_t>(a0)));
    }
  };


} } }

#endif
