//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SINC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SINC_HPP_INCLUDED

#if !defined(BOOST_SIMD_NO_INFINITIES)
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/scalar/is_inf.hpp>
#endif
#if !defined(BOOST_SIMD_NO_DENORMALS)
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/function/scalar/abs.hpp>
#endif
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/scalar/sin.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( sinc_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0) const BOOST_NOEXCEPT
    {
      #if !defined(BOOST_SIMD_NO_INFINITIES)
      if(is_inf(a0)) return Zero<A0>();
      #endif

      #if !defined(BOOST_SIMD_NO_DENORMALS)
      return bs::abs(a0) < Eps<A0>() ? One<A0>() : bs::sin(a0)/a0;
      #else
      return a0 ? bs::sin(a0)/a0 : One<A0>();
      #endif
    }
  };
} } }


#endif
