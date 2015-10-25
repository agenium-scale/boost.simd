//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EPS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EPS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <boost/simd/function/scalar/is_not_finite.hpp>
#include <boost/simd/function/scalar/exponent.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( eps_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const &) const BOOST_NOEXCEPT
    {
      return One<A0>();
    }
  };

  BOOST_DISPATCH_OVERLOAD ( eps_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    result_t operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      typedef std::numeric_limits<A0> lim;
      const A0 a = bs::abs(a0);
      if (is_not_finite(a))
      {
        return Nan<A0>();
      }
      else if (a < lim::min())
      {
        return Mindenormal<A0>();
      }
      else
      {
        using i_t = bd::as_integer_t<A0, unsigned>;
        i_t e1 = exponent(a)-lim::digits+1;
        return bitwise_cast<result_t>(bitwise_cast<i_t>(One<A0>())+(e1 << Nbmantissabits<A0>()));
      }
    }
  };
} } }


#endif
