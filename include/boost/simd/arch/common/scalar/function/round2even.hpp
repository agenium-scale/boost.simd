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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROUND2EVEN_HPP_INCLUDED


#include <boost/simd/constant/twotonmb.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/detail/enforce_precision.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/dispatch/function/overload.hpp>
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
    using result_t = A0;

    BOOST_FORCEINLINE result_t operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      detail::enforce_precision<A0> enforcer;

      const result_t v = bs::abs(a0);
      const result_t t2n = Twotonmb<result_t>();
      result_t d0 = (v+t2n);
      result_t d = (d0-t2n);
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
    using result_t = A0;

    BOOST_FORCEINLINE result_t operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };
} } }


#endif
