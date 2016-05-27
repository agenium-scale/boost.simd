//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_DETAIL_SCALAR_F_INVTRIG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_DETAIL_SCALAR_F_INVTRIG_HPP_INCLUDED

#include <boost/simd/function/horn.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_2lo.hpp>
#include <boost/simd/constant/pio_3.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/pio_4lo.hpp>
#include <boost/simd/constant/tan_3pio_8.hpp>
#include <boost/simd/constant/tanpio_8.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/twopio_3.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/bitofsign.hpp>
#include <boost/simd/function/scalar/bitwise_xor.hpp>
#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/function/scalar/is_eqz.hpp>
#include <boost/simd/function/scalar/is_inf.hpp>
#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/scalar/oneminus.hpp>
#include <boost/simd/function/scalar/oneplus.hpp>
#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/scalar/sqr.hpp>
#include <boost/simd/function/scalar/sqrt.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    namespace bd =  boost::dispatch;
    namespace bs =  boost::simd;

   template < class A0,
             class unit_tag,
             class style,
             class base_A0 = bd::scalar_of_t<A0>
  >
  struct invtrig_base{};

  template < class A0 >
  struct invtrig_base<A0,tag::radian_tag,tag::not_simd_type, float>
  {
    static BOOST_FORCEINLINE A0 asin(A0 a0) BOOST_NOEXCEPT
    {
      A0 sign, x, z;
      x = bs::abs(a0);
      sign = bitofsign(a0);
      if ((x < Constant<A0,0x38d1b717>())) return a0; //1.0e-4
      if ((x >  One<A0>())) return Nan<A0>();
      auto bx_larger_05    = (x > Half<A0>());
      if (bx_larger_05)
      {
        z = Half<A0>()*oneminus(x);
        x =  sqrt(z);
      }
      else
      {
        z = sqr(x);
      }
      A0 z1 = horn<A0,
        0x3e2aaae4,
        0x3d9980f6,
        0x3d3a3ec7,
        0x3cc617e3,
        0x3d2cb352
        > (z);
      z1 = fma(z1, z*x, x);
      if(bx_larger_05)
      {
        z1 = z1+z1;
        z1 = Pio_2<A0>()-z1;
      }
      return bitwise_xor(z1, sign);
    }

    static BOOST_FORCEINLINE A0 acos(const  A0& a0) BOOST_NOEXCEPT
    {
      if (a0 < Mhalf<A0>())
        return Pi<A0>()-asin( sqrt(oneplus(a0)*Half<A0>()))*Two<A0>();
      else if (a0 > Half<A0>())
        return asin( sqrt(oneminus(a0)*Half<A0>()))*Two<A0>();
      return (Pio_2<A0>()-asin(a0));
    }

    static BOOST_FORCEINLINE A0 atan(A0 a0) BOOST_NOEXCEPT
    {
      A0 x  = kernel_atan(a0);
      return bitwise_xor(x, bitofsign(a0));
    }

    static BOOST_FORCEINLINE A0 kernel_atan(A0 a0) BOOST_NOEXCEPT
    {
      if (is_eqz(a0))  return Zero<A0>();
      if (is_inf(a0))  return Pio_2<A0>();
      A0 x = bs::abs(a0);
      A0 y = 0.0;
      A0 more = Zero<A0>();
      if( x > Tan_3pio_8<A0>())
      {
        y = Pio_2<A0>();
        more = Pio_2lo<A0>();
        x = -rec(x);
      }
      else if( x > Tanpio_8<A0>())
      {
        y = Pio_4<A0>();
        more =  Pio_4lo<A0>();
        x = minusone(x)/oneplus(x);
      }
      A0 z = sqr(x);
      A0 z1 = horn<A0
        , 0xbeaaaa2aul  // -3.3333293e-01
        , 0x3e4c925ful  //  1.9991724e-01
        , 0xbe0e1b85ul  // -1.4031009e-01
        , 0x3da4f0d1ul  //  8.5460119e-02
        > (z);
    z1 = fma(x, z1*z, x);

      return y+(z1+more);
    }
  };
}
} }
#endif
