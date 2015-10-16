//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_IROUND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_IROUND_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/toints.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/function/overload.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
 BOOST_DISPATCH_OVERLOAD ( iround_
                         , (typename A0)
                         , bd::cpu_
                         , bd::generic_<bd::arithmetic_<A0> >
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const
    {
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( iround_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_<bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0> operator() ( A0 const& a0) const
    {
      A0 inc = if_else(is_ltz(a0), Mhalf<A0>(), Half<A0>());
      return toints(a0+inc);
    }
  };
} } }


#endif
