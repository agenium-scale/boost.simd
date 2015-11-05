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
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_POW_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_POW_HPP_INCLUDED

#include <boost/simd/constant/nan.hpp>
#include <boost/simd/function/scalar/is_flint.hpp>
#include <boost/simd/function/scalar/is_ltz.hpp>
#include <boost/simd/function/scalar/is_odd.hpp>
#include <boost/simd/function/scalar/pow_abs.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( pow_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      bool ltza0 = is_ltz(a0);
      if( (ltza0 && !is_flint(a1)) ) return Nan<A0>();
      A0 z = pow_abs(a0, a1);
      return  (ltza0 && is_odd(a1)) ? -z : z;
    }
  };
} } }


#endif
