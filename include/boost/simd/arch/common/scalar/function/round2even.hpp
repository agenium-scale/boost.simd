//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROUND2EVEN_HPP_INCLUDED


#include <boost/simd/constant/twotonmb.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/detail/enforce_precision.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( round2even_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      detail::enforce_precision<A0> enforcer;

      const A0 v = bs::abs(a0);
      const A0 t2n = Twotonmb<A0>();
      A0 d0 = (v+t2n);
      A0 d = (d0-t2n);
      d = (v < t2n)?d:v;
      return a0 < Zero<A0>() ? -d : d;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( round2even_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::integer_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };
} } }


#endif
