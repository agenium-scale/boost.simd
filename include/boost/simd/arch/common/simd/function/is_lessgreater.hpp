//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_LESSGREATER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_LESSGREATER_HPP_INCLUDED

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/bitwise_and.hpp>
#include <boost/simd/function/simd/is_ord.hpp>
#include <boost/simd/function/simd/is_not_equal.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( is_lessgreater_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_< bs::logical_<A0>, X >
                          , bs::pack_< bs::logical_<A0>, X >
                          )
  {
    BOOST_FORCEINLINE auto operator() ( A0 a0 , A0 a1 ) const BOOST_NOEXCEPT
      -> decltype(is_not_equal(a0, a1))
    {
      return  is_not_equal(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_lessgreater_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_< bd::arithmetic_<A0>, X >
                          , bs::pack_< bd::arithmetic_<A0>, X >
                          )
  {
    BOOST_FORCEINLINE auto operator() ( A0 a0 , A0 a1 ) const BOOST_NOEXCEPT
      -> decltype(is_not_equal(a0, a1))
    {
      return  is_not_equal(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_lessgreater_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_< bd::floating_<A0>, X >
                          , bs::pack_< bd::floating_<A0>, X >
                          )
  {
    BOOST_FORCEINLINE auto operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
   -> decltype(is_not_equal(a0, a1))
    {
      return bitwise_and(is_ord(a0,a1), is_not_equal(a0, a1));
    }
  };

} } }


#endif
