//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_COMMON_SIMD_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_COMMON_SIMD_FUNCTION_TOINT_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
//#include <boost/simd/function/simd/split_low.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( toint_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE  bd::as_integer_t<A0>  operator() ( const A0 & a) const BOOST_NOEXCEPT
    {
      return {int64_t(a[0]), int64_t(a[1])};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( toint_
                          , (typename A0)
                          , bs::avx_
                          , bs::pack_<bd::double_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE  bd::as_integer_t<A0>  operator() ( const A0 & a) const BOOST_NOEXCEPT
    {
      return {int64_t(a[0]), int64_t(a[1]), int64_t(a[2]), int64_t(a[3])};
    }
  };

} } }

#endif
