//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROUND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROUND_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/ceil.hpp>
#include <boost/simd/function/simd/logical_andnot.hpp>
#include <boost/simd/function/simd/copysign.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/is_flint.hpp>
#include <boost/simd/function/simd/is_greater.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/none.hpp>
#include <boost/simd/function/simd/round2even.hpp>
#include <boost/simd/function/simd/tenpower.hpp>
#include <boost/simd/function/simd/trunc.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/mpl/equal_to.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(round_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::integer_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return a0;
      }
   };

   BOOST_DISPATCH_OVERLOAD(round_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        auto isf = logical_andnot(is_flint(a0+a0), is_flint(a0));
        auto r1 = round2even(a0);
//        if (none(isf)) return r1;
        return if_else(isf, -trunc(-a0), r1);
      }
   };

   BOOST_DISPATCH_OVERLOAD(round_
                             , (typename A0, typename A1, typename X)
                             , bd::cpu_
                             , bs::pack_<bd::floating_<A0>, X>
                             , bs::pack_<bd::integer_<A1>, X>
                             )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
        A0 fac = tenpower(a1);
        A0 tmp1 = round(a0*fac)/fac;
        return if_else(is_ltz(a1), round(tmp1), tmp1);
      }
   };

   BOOST_DISPATCH_OVERLOAD(round_
                          , (typename A0, typename A1, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bd::scalar_<bd::unsigned_<A1>>
                          )
   {
     BOOST_FORCEINLINE A0 operator()(A0 const & a0,  A1 const & a1) const
      {
        using itype_t = bd::as_integer_t<A0, unsigned>;
        return round(a0, splat<itype_t>(a1));
      }
   };

   BOOST_DISPATCH_OVERLOAD(round_
                          , (typename A0, typename X, typename A1)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bd::scalar_<bd::integer_<A1>>
                          )
   {
     BOOST_FORCEINLINE A0 operator()(A0 const & a0,  A1 const & a1) const
      {
        using itype_t = bd::as_integer_t<A0, unsigned>;
        return round(a0, splat<itype_t>(a1));
      }
   };
} } }

#endif
