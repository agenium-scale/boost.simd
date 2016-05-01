//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ACOSH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ACOSH_HPP_INCLUDED

#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/oneotwoeps.hpp>
#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/function/scalar/log1p.hpp>
#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/scalar/sqr.hpp>
#include <boost/simd/function/scalar/sqrt.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( acosh_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0) const BOOST_NOEXCEPT
    {
      A0 t = minusone(a0);
      if(BOOST_LIKELY(t <= Oneotwoeps<A0>()))
        return log1p(t+bs::sqrt(t+t+sqr(t)));
      else
        return log(t)+Log_2<A0>();
    }
  };
} } }


#endif
