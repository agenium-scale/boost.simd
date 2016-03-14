//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_STORE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_STORE_HPP_INCLUDED

#include <boost/simd/detail/aliasing.hpp>
#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( store_
                          , (typename Vec, typename Pointer)
                          , bs::sse2_
                          , bs::pack_ < bd::single_ < Vec>, bs::sse_>
                          , bd::pointer_<bd::scalar_<bd::single_<Pointer>>,1u>
                          )
  {
    BOOST_FORCEINLINE void operator() (const Vec& a0, Pointer a1) const BOOST_NOEXCEPT
    {
      _mm_storeu_ps(a1,a0);
    }
  };

} } }

#endif
