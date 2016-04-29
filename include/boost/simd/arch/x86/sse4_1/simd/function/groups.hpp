//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_GROUPS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_GROUPS_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/shift_right.hpp>
#include <boost/dispatch/meta/downgrade.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;

  BOOST_DISPATCH_OVERLOAD ( groups_
                          , (typename A0)
                          , bs::sse4_1_
                          , bs::pack_<bd::uint32_<A0>, bs::sse_>
                          , bs::pack_<bd::uint32_<A0>, bs::sse_>
                         )
  {
    using result = bd::downgrade_t<A0>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0
                                        , const A0 & a1 ) const BOOST_NOEXCEPT
    {
      A0 mask1 = bs::Constant<A0,0x7FFFFFFF>();
      A0 mask2 = bs::Constant<A0,0xF0000000>();
      return _mm_packus_epi32( bitwise_and(a0, mask1) | shift_right(bitwise_and(a0, mask2), 1)
                             , bitwise_and(a1, mask1) | shift_right(bitwise_and(a1, mask2), 1)
                             );
    }
  };

} } }

#endif
