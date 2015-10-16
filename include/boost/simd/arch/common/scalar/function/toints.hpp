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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TOINTS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TOINTS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/saturate.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/scalar/is_nan.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( toints_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::int_<A0> >
                          )
  {
    using result_t = A0;

    BOOST_FORCEINLINE result_t operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( toints_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::uint_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0, signed>;

    BOOST_FORCEINLINE result_t operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return result_t(saturate<result_t>(a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( toints_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0>;

    BOOST_FORCEINLINE result_t operator() ( A0 a0) const BOOST_NOEXCEPT
    {
    #ifndef BOOST_SIMD_NO_NANS
      if (simd::is_nan(a0)) return Zero<result_t>();
    #endif
      if (a0 >= Valmax<result_t>()) return Valmax<result_t>();
      if (a0 <= Valmin<result_t>()) return Valmin<result_t>();
      return result_t(a0);
    }
  };
} } }


#endif
