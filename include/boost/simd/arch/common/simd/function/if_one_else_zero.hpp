//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/if_else_zero.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(if_one_else_zero_

                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return bs::if_else_zero(a0, One<A0>());
      }
   };

   BOOST_DISPATCH_OVERLOAD(if_one_else_zero_

                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bs::logical_<A0>, X>
                          )
   {
      using result = A0;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return bs::if_else_zero(a0, One<result>());
      }
   };

} } }

#endif

