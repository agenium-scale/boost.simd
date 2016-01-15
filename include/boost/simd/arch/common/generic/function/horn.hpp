//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_HORN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_HORN_HPP_INCLUDED

#include <boost/simd/constant/constant.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  template < typename T>
  BOOST_FORCEINLINE T horn(T) BOOST_NOEXCEPT
  {
    return bs::Zero<T>();
  }

  template < typename T,  uintmax_t Coef>
  BOOST_FORCEINLINE T horn(const T & ) BOOST_NOEXCEPT
  {
    return  bs::Constant<T, Coef>();
  }

  template < typename T, uintmax_t Coef0, uintmax_t Coef1, uintmax_t... Args>
  BOOST_FORCEINLINE T horn(const T & x) BOOST_NOEXCEPT
  {
    return bs::fma(x, horn < T, Coef1, Args...>(x),  bs::Constant<T, Coef0>());
  }

} }


#endif
