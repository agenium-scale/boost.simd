//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SINHC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SINHC_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/hyperbolic/function/details/sinhc_kernel.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/sdk/config.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/maxlog.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/average.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/exp.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/inbtrue.hpp>
#include <boost/simd/function/simd/is_greater.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/rec.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( sinhc_
                          , (typename A0, typename X)
                          , bs::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        //////////////////////////////////////////////////////////////////////////////
        // if x = abs(a0) is less than 1 sinhc is computed using a polynomial(float)
        // respectively rational(double) approx inspired from cephes sinh approx.
        // else according x < Threshold e =  exp(x) or exp(x/2) is respectively
        // computed
        // * in the first case sinh is ((e-rec(e))/2)/x
        // * in the second     sinh is (e/2/x)*e (avoiding undue overflow)
        // Threshold is Maxlog - Log_2
        //////////////////////////////////////////////////////////////////////////////
        using bA0 =  bs::as_logical_t<A0>;
        A0 x = bs::abs(a0);
        bA0 lt1= lt(x, One<A0>());
        std::size_t nb = inbtrue(lt1);
        A0 z = Zero<A0>();
        if( nb > 0)
        {
          z = detail::sinhc_kernel<A0>::compute(sqr(x));
          if(nb >= meta::cardinal_of<A0>::value) return z;
        }
        bA0 test1 = gt(x, Maxlog<A0>()-Log_2<A0>());
        A0 fac = if_else(test1, Half<A0>(), One<A0>());
        A0 tmp = exp(x*fac);
        A0 tmp1 = (Half<A0>()*tmp)/x;
        A0 r =  if_else(test1, tmp1*tmp, average(tmp, -rec(tmp))/x);
        #ifndef BOOST_SIMD_NO_INFINITIES
        r = if_else(eq(x, Inf<A0>()), x, r);
        #endif
        return if_else(lt1, z, r);
      }
   };

} } }

#endif
