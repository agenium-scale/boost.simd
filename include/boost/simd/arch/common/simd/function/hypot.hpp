//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_HYPOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_HYPOT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/maxexponentm1.hpp>
#include <boost/simd/constant/minexponent.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/exponent.hpp>
#include <boost/simd/function/simd/ldexp.hpp>
#include <boost/simd/function/simd/max.hpp>
#include <boost/simd/function/simd/min.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/simd/function/simd/sqrt.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/logical_and.hpp>
#include <boost/simd/function/simd/logical_or.hpp>
#include <boost/simd/function/simd/is_inf.hpp>
#include <boost/simd/function/simd/is_nan.hpp>
#include <boost/simd/constant/inf.hpp>
#endif


namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(hypot_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        using iA0 = bd::as_integer_t<A0>;
        A0 r =  bs::abs(a0);
        A0 i =  bs::abs(a1);
        iA0 e =  exponent(bs::max(i, r));
        e = bs::min(bs::max(e,Minexponent<A0>()),Maxexponentm1<A0>());
        A0 res =  ldexp(sqrt(sqr(ldexp(r, -e))+sqr(ldexp(i, -e))), e);
        #ifndef BOOST_SIMD_NO_INVALIDS
        auto test = logical_or(logical_and(is_nan(a0), is_inf(a1)),
                              logical_and(is_nan(a1), is_inf(a0)));
        return if_else(test, Inf<A0>(), res);
        #else
        return res;
        #endif
      }
   };

} } }

#endif

