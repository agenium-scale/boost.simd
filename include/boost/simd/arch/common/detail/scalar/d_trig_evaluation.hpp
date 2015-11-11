//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_DETAIL_SCALAR_D_TRIG_EVALUATION_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_DETAIL_SCALAR_D_TRIG_EVALUATION_HPP_INCLUDED

#include <boost/simd/arch/common/detail/generic/horner.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/function/scalar/oneminus.hpp>
#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/scalar/sqr.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    namespace bd =  boost::dispatch;
    namespace bs =  boost::simd;

    template < class A0>
    struct trig_evaluation < A0, tag::not_simd_type, double >
    {

      static inline A0 cos_eval(A0 z) BOOST_NOEXCEPT
      {
        const A0 y = horner< BOOST_SIMD_HORNER_COEFF_T(A0, 7
                                                    , ( 0x3da8ff831ad9b219ll,
                                                        0xbe21eea7c1e514d4ll,
                                                        0x3e927e4f8e06d9a5ll,
                                                        0xbefa01a019ddbcd9ll,
                                                        0x3f56c16c16c15d47ll,
                                                        0xbfa5555555555551ll,
                                                        0x3fe0000000000000ll) ) > (z);
        return oneminus(y*z);
      }

      static inline A0 sin_eval(A0 z, A0 x) BOOST_NOEXCEPT
      {
        const A0 y1 = horner< BOOST_SIMD_HORNER_COEFF_T(A0, 6
                                                     , ( 0x3de5d8fd1fcf0ec1ll,
                                                         0xbe5ae5e5a9291691ll,
                                                         0x3ec71de3567d4896ll,
                                                         0xbf2a01a019bfdf03ll,
                                                         0x3f8111111110f7d0ll,
                                                         0xbfc5555555555548ll) ) > (z);
        return fma(y1*z,x,x);
      }

      static inline A0 base_tan_eval( A0 x) BOOST_NOEXCEPT
      {
        const A0 zz = sqr(x);
        const A0 num = horner< BOOST_SIMD_HORNER_COEFF_T(A0, 3
                                                      , ( 0xc0c992d8d24f3f38ll,
                                                          0x413199eca5fc9dddll,
                                                          0xc1711fead3299176ll))>(zz);
        const A0 den = horner< BOOST_SIMD_HORNER_COEFF_T(A0, 5
                                                      , (0x3ff0000000000000ll,
                                                         0x40cab8a5eeb36572ll,
                                                         0xc13427bc582abc96ll,
                                                         0x4177d98fc2ead8efll,
                                                         0xc189afe03cbe5a31ll))>(zz);
        return x+ x*(zz*(num/den));
      }

      static inline A0 tan_eval(A0 x, const int n ) BOOST_NOEXCEPT
      {
        A0 y =  base_tan_eval(x);
        if (n == 1) return y;  else return -rec(y);
      }
      static inline A0 cot_eval(A0 x, const int n ) BOOST_NOEXCEPT
      {
        A0 y =  base_tan_eval(x);
        if (n == 1) return rec(y);  else return -y;
      }
    };
  }
} }
#endif
