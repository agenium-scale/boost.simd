//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SQRS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SQRS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/sqr.hpp>
#include <boost/simd/function/scalar/abss.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/sqrtvalmax.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( sqrs_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::int_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return abss(a0) > Sqrtvalmax<A0>() ? Valmax<A0>() : sqr(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( sqrs_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::uint_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return a0 > Sqrtvalmax<A0>() ? Valmax<A0>() : sqr(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( sqrs_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return sqr(a0);
    }
  };
} } }


#endif
