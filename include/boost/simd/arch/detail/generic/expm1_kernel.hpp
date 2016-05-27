//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_DETAIL_GENERIC_EXPM1_KERNEL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_DETAIL_GENERIC_EXPM1_KERNEL_HPP_INCLUDED

#include <boost/simd/function/fast.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/invlog_2.hpp>
#include <boost/simd/constant/log_2hi.hpp>
#include <boost/simd/constant/log_2lo.hpp>
#include <boost/simd/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/six.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/expm1.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/simd/function/fnms.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/oneplus.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/round2even.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/arch/detail/scalar/horner.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    namespace bd =  boost::dispatch;
    namespace bs =  boost::simd;

    template < typename A0, typename sA0 = bd::scalar_of_t<A0> >
    struct expm1_kernel;

    template < typename A0 >
    struct expm1_kernel < A0, float >
    {
      // computes expm1 for float or float vectors
      static BOOST_FORCEINLINE A0 expm1(const A0& a0) BOOST_NOEXCEPT
      {
        using i_t = bd::as_integer_t<A0>;
        using s_t = bd::scalar_of_t<A0>;
        A0 k  = round2even(Invlog_2<A0>()*a0);
        A0 x = fnms(k, Log_2hi<A0>(), a0);
        x =  fnms(k, Log_2lo<A0>(), x);
        A0 hx  = x*Half<A0>();
        A0 hxs = x*hx;
        A0 r1 = horner<BOOST_SIMD_HORNER_COEFF_T(s_t, 3,
                                          (0X3ACF6DB4UL, // 1.5825541E-03
                                           0XBD08887FUL, // -3.3333298E-02
                                           0X3F800000UL) // 1
                                         )> (hxs);
        A0 t  = fnms(r1, hx, Three<A0>());
        A0 e  = hxs*((r1-t)/(Six<A0>() - x*t));
        e  = fms(x, e, hxs);
        i_t ik =  toint(k);
        A0 two2mk = bitwise_cast<A0>(shift_left(Maxexponent<A0>()-ik,Nbmantissabits<s_t>()));
        A0 y = oneminus(two2mk)-(e-x);
        return fast_(ldexp)(y, ik);
      }
    };

    template < typename A0 >
    struct expm1_kernel < A0, double >
    {
      // computes expm1 for  double or double vectors
      static  BOOST_FORCEINLINE A0 expm1(const A0& a0) BOOST_NOEXCEPT
      {
        using i_t = bd::as_integer_t<A0>;
        using s_t = bd::scalar_of_t<A0>;
        A0 k  = round2even(Invlog_2<A0>()*a0);
        A0 hi = fnms(k, Log_2hi<A0>(), a0);
        A0 lo = k*Log_2lo<A0>();
        A0 x  = hi-lo;
        A0 hxs = sqr(x)*Half<A0>();
        A0 r1 = horner<BOOST_SIMD_HORNER_COEFF_T(s_t, 6,
                                          (0XBE8AFDB76E09C32DULL,
                                           0X3ED0CFCA86E65239ULL,
                                           0XBF14CE199EAADBB7ULL,
                                           0X3F5A01A019FE5585ULL,
                                           0XBFA11111111110F4ULL,
                                           0X3FF0000000000000ULL)
                                         )> (hxs);
        A0 t  = Three<A0>()-r1*Half<A0>()*x;
        A0 e  = hxs*((r1-t)/(Six<A0>() - x*t));
        A0 c = (hi-x)-lo;
        e  = (x*(e-c)-c)-hxs;
        i_t ik =  toint(k);
        A0 two2mk = bitwise_cast<A0>(shift_left(Maxexponent<A0>()-ik,Nbmantissabits<s_t>()));
        A0 ct1= oneminus(two2mk)-(e-x);
        A0 ct2= oneplus((x-(e+two2mk)));
        A0 y = if_else((k < Ratio<A0, 20>()),ct1,ct2);
        return fast_(ldexp)(y, ik);
      }
    };
  }
} }
#endif
