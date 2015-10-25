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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SIGN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SIGN_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/is_ltz.hpp>
#include <boost/simd/function/scalar/is_gtz.hpp>
#include <boost/simd/function/scalar/shift_right.hpp>
#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/scalar/is_nan.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( sign_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return shift_right(a0, (sizeof(A0)*8-1)) - shift_right(-a0, (sizeof(A0)*8-1));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( sign_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::unsigned_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return !!a0;
    }
  };


  BOOST_DISPATCH_OVERLOAD ( sign_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      A0 r = bool(is_gtz(a0))-bool(is_ltz(a0));
#ifdef BOOST_SIMD_NO_NANS
      return r;
#else
      return is_nan(a0) ? a0 : r;
#endif
    }
  };
} } }


#endif
