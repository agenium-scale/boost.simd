//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LDEXP_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/shift_left.hpp>
#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/simd/constant/maxexponent.hpp>
#include <boost/simd/constant/limitexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( ldexp_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::integer_<A0> >
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A1 a1) const BOOST_NOEXCEPT
    {
      return (a1>0)?(a0<<a1):(a0>>a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( ldexp_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A1 a1) const BOOST_NOEXCEPT
    {
      using i_t = bd::as_integer_t<A0>;
      i_t e =  a1;
      A0 f = One<A0>();
    #ifndef BOOST_SIMD_NO_DENORMALS
      if (BOOST_UNLIKELY((e < Minexponent<A0>())))//meta::constant_value<tag::Minexponent, A0>::value)))
      {
        e -= Minexponent<A0>();
        f = Smallestposval<A0>();
      }
    #endif
      i_t b = (e == Limitexponent<A0>());
      f += A0(b);
      e -= b;
      e += Maxexponent<A0>();
      e = shift_left(e, Nbmantissabits<A0>());
      return a0*bitwise_cast<A0>(e)*f;
    }
  };
} } }


#endif
