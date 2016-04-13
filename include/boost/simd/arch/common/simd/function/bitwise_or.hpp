//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_OR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_OR_HPP_INCLUDED
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD(bitwise_or_
                         , (typename A0,typename A1,typename X)
                         , bd::cpu_
                         , bs::pack_<bd::arithmetic_<A0>,X>
                         , bs::pack_<bd::arithmetic_<A1>,X>
                         )

  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A1& a1
                                   , typename std::enable_if<
                                     sizeof(A1) == sizeof(A0)
                                     >::type* = 0
      ) const BOOST_NOEXCEPT
      {
        return bitwise_or(a0, simd::bitwise_cast<A0>(a1));
      }
  };

  BOOST_DISPATCH_OVERLOAD(bitwise_or_
                         , (typename A0,typename X)
                         , bd::cpu_
                         , bs::pack_<bd::floating_<A0>,X>
                         , bs::pack_<bd::arithmetic_<A0>,X>
                         )

  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1
                                   ) const BOOST_NOEXCEPT
    {
      using iA0 = bd::as_integer_t<A0>;
      return bitwise_cast<A0>(bitwise_or(bitwise_cast<iA0>(a0), a1));
    }
  };
} } }

#endif
