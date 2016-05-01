//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_POW_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_POW_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/function/scalar/is_flint.hpp>
#include <boost/simd/function/scalar/is_inf.hpp>
#include <boost/simd/function/scalar/is_ltz.hpp>
#include <boost/simd/function/scalar/is_negative.hpp>
#include <boost/simd/function/scalar/is_odd.hpp>
#include <boost/simd/function/scalar/pow_abs.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    inline A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      auto ltza0 = is_ltz(a0);
      auto isinfa1 = is_inf(a1);
      if( a0 == Mone<A0>() && isinfa1 ) return One<A0>();
      if( ltza0 && !is_flint(a1) && !is_inf(a1) ) return Nan<A0>();
      A0 z = pow_abs(a0, a1);
      if (isinfa1) return z;
      return  (is_negative(a0) && is_odd(a1)) ? -z : z;
    }
  };
   BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0)
                          , bd::cpu_
                          , bs::std_tag
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    inline A0 operator() (const std_tag &,  A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return std::pow(a0, a1);
    }
  };
} } }


#endif
