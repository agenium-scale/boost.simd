//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MINNUM_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MINNUM_HPP_INCLUDED

#include <boost/simd/function/scalar/is_nan.hpp>
#include <boost/simd/function/scalar/min.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
 BOOST_DISPATCH_OVERLOAD ( minnum_
                         , (typename A0)
                         , bd::cpu_
                         , bd::scalar_< bd::arithmetic_<A0> >
                         , bd::scalar_< bd::arithmetic_<A0> >
                         )
 {
   BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return simd::min(a0, a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( minnum_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      if (is_nan(a0)) return a1;
      else return simd::min(a1, a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( minnum_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          , boost::simd::std_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1, std_tag const&) const BOOST_NOEXCEPT
    {
      return std::fmin(a0, a1);
    }
  };
} } }


#endif
