//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REM_PIO2_CEPHES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REM_PIO2_CEPHES_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/function/simd/round2even.hpp>
#include <boost/simd/function/simd/toint.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/minus.hpp>
#include <boost/simd/function/simd/bitwise_and.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/twoopi.hpp>
#include <boost/simd/constant/pio2_1.hpp>
#include <boost/simd/constant/pio2_2.hpp>
#include <boost/simd/constant/pio2_3.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/fusion/include/std_pair.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( rem_pio2_cephes_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_ < bd::floating_<A0> >
                          , bd::generic_ < bd::integer_<A1>  >
                          , bd::generic_ < bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 const& x, A1 & n, A0 & xr)
    {
      n = bs::rem_pio2_cephes(x, xr);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( rem_pio2_cephes_
                          , (typename A0)
                             , bd::cpu_
                            , bd::generic_ < bd::floating_<A0> >
                            )
  {
    using i_t = bd::as_integer_t<A0>;
    using result_t = std::pair<i_t, A0>              ;

    BOOST_FORCEINLINE result_t operator() ( A0 const& a0) const
    {
      A0 second;
      i_t const first = bs::rem_pio2_cephes(a0,second);
      return {first, second};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( rem_pio2_cephes_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    using i_t = bd::as_integer_t<A0>;
    BOOST_FORCEINLINE i_t operator() ( A0 const& x, A0 & xr) const
    {
      A0 xi =  bs::round2even(x*bs::Twoopi<A0>());
//       xr -= xi*bs::Pio2_2<A0>();//TODO
//       xr -= xi*bs::Pio2_3<A0>();
      xr  = x-xi*bs::Pio2_1<A0>();
      xr = xr-xi*bs::Pio2_2<A0>();
      xr = xr-xi*bs::Pio2_3<A0>();
      return bitwise_and(bs::toint(xi), Three<i_t>());
    }
  };
} } }


#endif
