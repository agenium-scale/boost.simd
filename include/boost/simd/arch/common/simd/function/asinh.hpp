//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ASINH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ASINH_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/polynomials/function/scalar/impl/horner.hpp>
#include <boost/simd/sdk/config.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/oneosqrteps.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/average.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/function/simd/hypot.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/inbtrue.hpp>
#include <boost/simd/function/simd/is_greater.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/log.hpp>
#include <boost/simd/function/simd/minusone.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/oneplus.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/sqr.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/simd/is_equal.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( asinh_
                          , (typename A0, typename X)
                          , bs::cpu_
                          , bs::pack_<bd::double_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        using bA0 =  bs::as_logical_t<A0>;
        A0 x =  bs::abs(a0);
        bA0 test = gt(x,Oneosqrteps<A0>());
        A0 z = if_else(test,minusone(x), x+sqr(x)/bs::oneplus(hypot(One<A0>(), x)));
        #ifndef BOOST_SIMD_NO_INFINITIES
        z = if_else(is_equal(x, Inf<A0>()),x, z);
        #endif
        z =  seladd(test, log1p(z), Log_2<A0>());
        return bitwise_xor(bitofsign(a0), z);
      }
   };

   BOOST_DISPATCH_OVERLOAD( asinh_
                          , (typename A0, typename X)
                          , bs::cpu_
                          , bs::pack_<bd::single_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        // Exhaustive test for: boost::dispatch::functor<bs::tag::asinh_, bs::tag::sse4_2_>
        //              versus: float(boost::math::asinh(double)
        //              With T: bs::native<float, bs::tag::sse_, void>
        //            in range: [-3.40282e+38, 3.40282e+38]
        // 4278190076 values computed.
        // 3619320676 values (84.60%)  within 0.0 ULPs
        //  658843138 values (15.40%)  within 0.5 ULPs
        //      26262 values ( 0.00%)  within 1.0 ULPs
        using bA0 =  bs::as_logical_t<A0>;
        using sA0 =  bd::scalar_of_t<A0>;
        A0 x = bs::abs(a0);
        bA0 lthalf = lt(x,Half<A0>());
        A0 x2 = bs::sqr(x);
        A0 z = Zero<A0>();
        std::size_t nb = inbtrue(lthalf);
        A0 bts = bitofsign(a0);
        if(nb > 0)
        {
          z = horner < NT2_HORNER_COEFF_T(sA0, 5,
                                          ( 0x3ca4d6e6
                                          , 0xbd2ee581
                                          , 0x3d9949b1
                                          , 0xbe2aa9ad
                                          , 0x3f800000
                                          )
                                         )> (x2)*x;
          if(nb >= meta::cardinal_of<A0>::value) return  b_xor(z, bts);
        }
        A0 tmp =  if_else(gt(x, Oneosqrteps<A0>()),
                         x, average(x, hypot(One<A0>(), x)));
       return b_xor(if_else(lthalf, z, log(tmp)+Log_2<A0>()), bts);
      }
   };

} } }

#endif
