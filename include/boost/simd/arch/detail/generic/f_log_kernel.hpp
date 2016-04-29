//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_DETAIL_GENERIC_F_LOG_KERNEL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_DETAIL_GENERIC_F_LOG_KERNEL_HPP_INCLUDED

#include <boost/simd/function/fast.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/simd/function/simd/frexp.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/tofloat.hpp>
#include <boost/simd/function/simd/seladd.hpp>
#include <boost/simd/function/simd/minusone.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/simd/function/simd/multiplies.hpp>

#include <boost/simd/constant/sqrt_2o_2.hpp>
#include <boost/simd/constant/mone.hpp>


#include <boost/simd/arch/detail/scalar/horner.hpp>
#include <boost/simd/logical.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <tuple>

namespace boost { namespace simd { namespace detail
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  template < class A0,
             class Style ,
             class base_A0 = bd::scalar_of_t<A0>
           >
  struct kernel{};

  template < class A0, class style>
  struct kernel< A0, style, float>
  {
    using i_t = bd::as_integer_t<A0, signed>;
    using s_t = bd::scalar_of_t<A0>;

    static BOOST_FORCEINLINE void log(const A0& a0,
                           A0& fe,
                           A0& x,
                           A0& x2,
                           A0& y) BOOST_NOEXCEPT
    {
      i_t e;
      std::tie(x, e) = fast_(frexp)(a0);
      auto xltsqrthf = (x < Sqrt_2o_2<A0>());
      fe = seladd(xltsqrthf, tofloat(e), Mone<A0>());
      x =  saturated_(minusone)(seladd(xltsqrthf, x, x));
      x2 = sqr(x);
      // performances informations using this kernel for nt2::log
      // exhaustive and bench tests with g++-4.7 sse4.2 or scalar give:
      // at most 0.5 ulp  for input in [0, 3.40282e+38]
      // 2130706656 values computed.
      // 2127648316 values (99.86%)  within 0.0 ULPs
      //    3058340 values (0.14%)   within 0.5 ULPs
      // bench produces  8.9 cycles/value (simd) 34.5 cycles/value (scalar) full computation
      // bench produces  7.1 cycles/value (simd) 32.2 cycles/value (scalar) with NO_DENORMALS, NO_INVALIDS etc.
      y =  horner< BOOST_SIMD_HORNER_COEFF_T( s_t
                                     , 8
                                     , (0xbda5dff0, //     -8.0993533e-02
                                        0x3e0229f9, //      1.2711324e-01
                                        0xbe04d6b7, //     -1.2972532e-01
                                        0x3e116e80, //      1.4202309e-01
                                        0xbe2a6aa0, //     -1.6642237e-01
                                        0x3e4cd0a3, //      2.0001464e-01
                                        0xbe800064, //     -2.5000298e-01
                                        0x3eaaaaa9  //      3.3333328e-01
                                       )
                                      )>(x)*x*x2;
    }
  };
} } }



#endif
