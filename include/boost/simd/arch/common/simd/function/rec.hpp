//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/if_one_else_zero.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(rec_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::uint_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return if_else_allbits(a0, if_one_else_zero(a0 == One<A0>()));
      }
   };

   BOOST_DISPATCH_OVERLOAD(rec_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::int_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return if_else(a0, if_else_zero(abs(a0) == One<A0>(), a0), Valmax<A0>());
      }
   };

   BOOST_DISPATCH_OVERLOAD(rec_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return One<A0>()/a0;
      }
   };

} } }

#endif

