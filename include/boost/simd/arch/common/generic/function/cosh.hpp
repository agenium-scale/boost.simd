//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_COSH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_COSH_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/maxlog.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/average.hpp>
#include <boost/simd/function/simd/exp.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_greater.hpp>
#include <boost/simd/function/simd/rec.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( cosh_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_<bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      //////////////////////////////////////////////////////////////////////////////
      // if x = abs(a0) according x < Threshold e =  exp(x) or exp(x/2) is
      // respectively computed
      // *  in the first case cosh (e+rec(e))/2
      // *  in the second     cosh is (e/2)*e (avoiding undue overflow)
      // Threshold is Maxlog - Log_2 defined in Maxshlog
      //////////////////////////////////////////////////////////////////////////////
      A0 x = bs::abs(a0);
      auto test1 = (x > Maxlog<A0>()-Log_2<A0>());
      A0 fac = if_else(test1, Half<A0>(), One<A0>());
      A0 tmp = exp(x*fac);
      A0 tmp1 = Half<A0>()*tmp;
      return if_else(test1, tmp1*tmp, bs::average(tmp, rec(tmp)));
    }
  };
} } }


#endif
