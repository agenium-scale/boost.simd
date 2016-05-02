//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REM_PIO2_STRAIGHT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REM_PIO2_STRAIGHT_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pio2_1.hpp>
#include <boost/simd/constant/pio2_2.hpp>
#include <boost/simd/constant/pio2_3.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/minus.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD (rem_pio2_straight_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_ < bd::floating_<A0> >
                          , bd::generic_ < bd::integer_<A1>  >
                          , bd::generic_ < bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 const& x, A1 & n, A0 & xr) BOOST_NOEXCEPT
    {
      n = bs::rem_pio2_straight(x, xr);
    }
  };

  BOOST_DISPATCH_OVERLOAD (rem_pio2_straight_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_ < bd::floating_<A0> >
                          )
  {
    using int_t = bd::as_integer_t<A0>;
    using result_t = std::pair<int_t, A0>;
    BOOST_FORCEINLINE result_t operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 second;
      int_t const first = rem_pio2_straight(a0,second);
      return {first, second};
    }
  };

  BOOST_DISPATCH_OVERLOAD (rem_pio2_straight_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    using int_t = bd::as_integer_t<A0>;
    BOOST_FORCEINLINE int_t operator() ( A0 const& x, A0 & xr) const BOOST_NOEXCEPT
    {
      xr = x-Pio2_1<A0>();
      xr = xr-Pio2_2<A0>();
      xr = xr-Pio2_3<A0>();
//       xr -= Pio2_2<A0>(); TODO
//       xr -= Pio2_3<A0>();
      return One<int_t>();
    }
  };
} } }


#endif
