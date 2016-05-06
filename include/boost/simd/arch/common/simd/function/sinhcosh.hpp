//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SINHCOSH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SINHCOSH_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/hyperbolic/function/details/sinh_kernel.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/maxlog.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/any.hpp>
#include <boost/simd/function/simd/average.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>
#include <boost/simd/function/simd/exp.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_greater.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/rec.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( sinhcosh_
                          , (typename A0, typename X)
                          , bs::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      using result = void;
     inline result operator()(A0 const& a0,A0 & a1,A0 & a2) const
      {
        //////////////////////////////////////////////////////////////////////////////
        // if x = abs(a0) is less than 1 sinh is computed using a polynomial(float)
        // respectively rational(double) approx from cephes.
        // else according x < Threshold e =  exp(x) or exp(x/2) is respectively
        // computed
        // *  in the first case sinh is (e-rec(e))/2 and cosh (e+rec(e))/2
        // *  in the second     sinh and cosh are (e/2)*e (avoiding undue overflow)
        // Threshold is Maxlog - Log_2 defined in Maxshlog
        //////////////////////////////////////////////////////////////////////////////
        using bA0 =  bs::as_logical_t<A0>;
        A0 x = bs::abs(a0);
        bA0 lt1= lt(x, One<A0>());
        A0 bts = bitofsign(a0);
        if(bs::any(lt1))
        {
          a1 = detail::sinh_kernel<A0>::compute(x, sqr(x));
        }
        bA0 test1 = gt(x, Maxlog<A0>()-Log_2<A0>());
        A0 fac = if_else(test1, Half<A0>(), One<A0>());
        A0 tmp = exp(x*fac);
        A0 tmp1 = Half<A0>()*tmp;
        A0 rtmp = rec(tmp);
        A0 r = if_else(test1, tmp1*tmp, tmp1-Half<A0>()*rtmp);
        a1 = b_xor(if_else(lt1, a1, r), bts);
        a2 = if_else(test1, r, bs::average(tmp, rtmp));
      }
   };

} } }

#endif
