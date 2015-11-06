//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_ATANH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_ATANH_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/bitofsign.hpp>
#include <boost/simd/function/scalar/bitwise_xor.hpp>
#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/function/scalar/log1p.hpp>
#include <boost/simd/function/scalar/oneminus.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>


namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( atanh_
                          , (typename A0)
                             , bd::cpu_
                            , bd::scalar_< bd::floating_<A0> >
                            )
  {
    // Exhaustive test for: boost::dispatch::functor<bs::tag::atanh_, boost::simd::tag::sse4_2_>
    //              versus: float(boost::simd::atanh(double))
    //              With T: float
    //            in range: [-1, 1]
    // 2130706432 values computed.
    // 1965486672 values (92.25%)  within 0.0 ULPs
    //  165215696 values (7.75%) within 0.5 ULPs in range [-9.999999404e-01, 9.999999404e-01].
    //            Example: -9.999999404e-01 returns -8.664339066e+00 instead of -8.664340019e+00
    //       4064 values (0.00%) within 1.0 ULPs in range [-1.243482381e-01, 1.243482381e-01].
    //            Example: -1.243482381e-01 returns -1.249951422e-01 instead of -1.249951646e-01

    BOOST_FORCEINLINE A0 operator() (A0 a0) const BOOST_NOEXCEPT
    {
      A0 absa0 = bs::abs(a0);
      A0 t =  absa0+absa0;
      A0 z1 = oneminus(absa0);
      return bitwise_xor(bitofsign(a0),
                         Half<A0>()*log1p((absa0 < Half<A0>())
                                          ? fma(t, absa0/z1, t)
                                          : t/z1)
                        );
    }
  };
} } }


#endif
