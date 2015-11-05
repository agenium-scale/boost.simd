//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_LOG1P_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_LOG1P_HPP_INCLUDED

#include <boost/simd/detail/enforce_precision.hpp>
#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/scalar/oneplus.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( log1p_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      detail::enforce_precision<A0> enforcer;

      if (Mone<A0>() > a0)   return Nan<A0>();
      #ifndef BOOST_SIMD_NO_INFINITIES
      if (a0 == Inf<A0>())   return Inf<A0>();
      #endif
      if (a0 == Mone<A0>())   return Minf<A0>();
      A0 u = oneplus(a0);
      return log(u)+(a0-minusone(u))/u;
    }
  };
} } }


#endif
