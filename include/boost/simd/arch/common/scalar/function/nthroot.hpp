//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NTHROOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NTHROOT_HPP_INCLUDED
#include <boost/simd/function/fast.hpp>

#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/function/scalar/is_inf.hpp>
#endif
#ifndef BOOST_SIMD_NO_INVALID
#include <boost/simd/function/scalar/is_nan.hpp>
#endif
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/is_ltz.hpp>
#include <boost/simd/function/scalar/is_odd.hpp>
#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/scalar/pow.hpp>
#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/scalar/sign.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( nthroot_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    inline A0 operator() ( A0 a0, A1 a1) const BOOST_NOEXCEPT
    {
#ifndef BOOST_SIMD_NO_INVALID
      if (is_nan(a0)) return a0;
#endif
      auto is_ltza0 = is_ltz(a0);
      auto is_odda1 = is_odd(a1);
      if (is_ltza0 && !is_odda1) return Nan<A0>();
      A0 x = bs::abs(a0);
      if (x == One<A0>()) return a0;
      if (!a1) return (x < One<A0>()) ? Zero<A0>() : sign(a0)*Inf<A0>();
      if (!a0) return Zero<A0>();
#ifndef BOOST_SIMD_NO_INFINITIES
      if (is_inf(a0)) return (a1) ? a0 : One<A0>();
#endif
      A0 aa1 = static_cast<A0>(a1);
      A0 y = bs::pow(x,rec(aa1));
      // Correct numerical errors (since, e.g., 64^(1/3) is not exactly 4)
      // by one iteration of Newton's method
      if (y) y -= (bs::pow(y, aa1) - x) / (aa1* bs::pow(y,minusone(aa1)));
      return (is_ltza0 && is_odda1)? -y : y;
    }
  };
  BOOST_DISPATCH_OVERLOAD ( nthroot_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    inline A0 operator() (const fast_tag &,  A0 a0, A1 a1
                         ) const BOOST_NOEXCEPT
    {
      auto is_ltza0 = is_ltz(a0);
      auto is_odda1 = is_odd(a1);
      if (is_ltza0 && !is_odda1) return Nan<A0>();
      A0 x = bs::abs(a0);
      if (x == One<A0>()) return a0;
      if (!a1) return (x < One<A0>()) ? Zero<A0>() : sign(a0)*Inf<A0>();
      if (!a0) return Zero<A0>();
      A0 aa1 = static_cast<A0>(a1);
      A0 y = bs::pow(x,rec(aa1));
      return (is_ltza0 && is_odda1)? -y : y;
    }
  };
} } }


#endif
