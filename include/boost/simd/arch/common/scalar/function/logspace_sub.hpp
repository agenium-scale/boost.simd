//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGSPACE_SUB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGSPACE_SUB_HPP_INCLUDED

#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/function/scalar/exp.hpp>
#include <boost/simd/function/scalar/expm1.hpp>
#include <boost/simd/function/scalar/is_eqz.hpp>
#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/function/scalar/log1p.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( logspace_sub_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      A0 x =  a1-a0;
      if(is_eqz(x)) return Minf<A0>();
      A0 tmp = (x > -Log_2<A0>()) ? bs::log(-expm1(x)) : bs::log1p(-exp(x));
      return a0 + tmp;
    }
  };
} } }


#endif
