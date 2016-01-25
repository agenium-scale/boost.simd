//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_RSHL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_RSHL_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_gtz.hpp>
#include <boost/simd/function/simd/shift_left.hpp>
#include <boost/simd/function/simd/shr.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>

#ifndef NDEBUG
#include <boost/simd/function/simd/max.hpp>
#include <boost/simd/constant/zero.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(rshl_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          , bd::generic_<bd::integer_<A1>>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
        #ifndef NDEBUG
        return if_else(is_gtz(a1), shl(a0, max(Zero<A1>(), a1)), shr(a0, max(Zero<A1>(), -a1)));
        #else
        return if_else(is_gtz(a1), shl(a0, a1), shr(a0, -a1));
        #endif
      }
   };

   BOOST_DISPATCH_OVERLOAD(rshl_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          , bd::generic_<bd::unsigned_<A1>>
                          )
   {
     BOOST_FORCEINLINE A0 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
     {
       return shl(a0, a1);
     }
   };


} } }

#endif

