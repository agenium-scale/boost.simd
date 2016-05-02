//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGSPACE_ADD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOGSPACE_ADD_HPP_INCLUDED

#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/scalar/is_nan.hpp>
#endif
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/scalar/exp.hpp>
#include <boost/simd/function/scalar/log1p.hpp>
#include <boost/simd/function/scalar/max.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( logspace_add_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      A0 tmp = -bs::abs(a0-a1);
      A0 r = bs::max(a0,a1)+bs::log1p(bs::exp(tmp));
    #ifndef BOOST_SIMD_NO_NANS
      return is_nan(tmp) ? a0+a1 : r;
    #else
      return r;
    #endif
    }
  };
} } }


#endif
