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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MOD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MOD_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/selsub.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/divfloor.hpp>
#include <boost/simd/function/idivfloor.hpp>
#include <boost/simd/function/multiplies.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( mod_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_<bd::floating_<A0> >
                          , bd::generic_<bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0  a1) const BOOST_NOEXCEPT
    {
      return selsub(is_nez(a1),a0,divfloor(a0,a1)*a1 );
    }
  };

  BOOST_DISPATCH_OVERLOAD ( mod_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_<bd::arithmetic_<A0> >
                          , bd::generic_<bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return selsub(is_nez(a1),a0,simd::multiplies(idivfloor(a0,a1),a1));
    }
  };
} } }


#endif
