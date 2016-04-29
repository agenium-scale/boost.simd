//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SUCCESSOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SUCCESSOR_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/simd/bitfloating.hpp>
#include <boost/simd/function/simd/bitinteger.hpp>
#include <boost/simd/function/simd/if_allbits_else.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_gez.hpp>
#include <boost/simd/function/simd/is_greater.hpp>
#include <boost/simd/function/simd/is_nan.hpp>
#include <boost/simd/function/simd/is_not_equal.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/oneplus.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/seladd.hpp>
#include <boost/assert.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(successor_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return seladd(is_not_equal(a0, Valmax<A0>()), a0, One<A0>());
      }
   };

   BOOST_DISPATCH_OVERLOAD(successor_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return if_allbits_else(is_nan(a0), bitfloating(saturated_(oneplus)(bitinteger(a0))));
      }
   };

   BOOST_DISPATCH_OVERLOAD(successor_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::integer_<A0>, X>
                          , bs::pack_<bd::integer_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        BOOST_ASSERT_MSG(assert_all(is_gez(a1)), "successor rank must be non negative");
        return if_else( bs::is_greater(Valmax<A0>()-a1, a0),
                        a0+a1,
                        Valmax<A0>());
      }
   };

   BOOST_DISPATCH_OVERLOAD(successor_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::integer_<A1>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
        BOOST_ASSERT_MSG(assert_all(is_gez(a1)), "successor rank must be non negative");
        return if_allbits_else(is_nan(a0), bitfloating(saturated_(plus)(bitinteger(a0), a1)));
      }
   };

} } }

#endif

