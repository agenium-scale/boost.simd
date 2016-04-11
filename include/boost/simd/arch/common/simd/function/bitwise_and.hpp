//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/dispatch/function/overload.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD(bitwise_and_
                         , (typename A0,typename A1)
                         , bs::simd_
                         , bs::pack_<bd::arithmetic_<A0>,bs::simd_native_>
                         , bs::pack_<bd::arithmetic_<A1>,bs::simd_native_>
                         )

  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A1& a1 ) const BOOST_NOEXCEPT
    {
      return bitwise_and(a0, simd::bitwise_cast<A0>(a1));
    }
   };

  BOOST_DISPATCH_OVERLOAD_IF(bitwise_and_
                            , (typename A0,typename A1)
                            , (brigand::not_<std::is_same<A0,A1>>)
                            , bs::simd_
                            , bs::pack_<bd::arithmetic_<A0>,bs::simd_emulation_>
                            , bs::pack_<bd::arithmetic_<A1>,bs::simd_emulation_>
                            )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A1& a1 ) const BOOST_NOEXCEPT
    {
      return bitwise_and(a0, simd::bitwise_cast<A0>(a1));
    }
   };
 } } }

#endif
