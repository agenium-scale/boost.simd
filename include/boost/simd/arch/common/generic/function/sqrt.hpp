//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SQRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SQRT_HPP_INCLUDED

#include <boost/simd/function/fast.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/assert.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/rsqrt.hpp>
#include <boost/simd/detail/math.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0  a0) const BOOST_NOEXCEPT
    {
      return if_else_zero(a0, a0 * fast_(rsqrt)(a0));
    }
  };
  BOOST_DISPATCH_OVERLOAD ( sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::generic_< bd::integer_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0 a0) const BOOST_NOEXCEPT
    {
      return sqrt(a0);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( sqrt_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::integer_<A0> >
                          , boost::simd::assert_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, assert_tag const& ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(bs::assert_all(is_positive(a0)),
                       "sqrt integer domain is restricted to positive integer.");
      return sqrt(a0);
    }
  };
} } }


#endif
