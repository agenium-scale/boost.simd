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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SQRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SQRT_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/is_gez.hpp>
#include <boost/simd/math.hpp>
#include <boost/assert.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::double_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0  a0) const BOOST_NOEXCEPT
    {
      return ::sqrt(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::single_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      #ifdef BOOST_SIMD_HAS_SQRTF
      return ::sqrtf(a0);
      #else
      return std::sqrt(a0);
      #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::integer_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(is_gez(a0), "sqrt input is negative");

      return A0(bs::sqrt(double(a0)));
    }
  };
} } }


#endif
