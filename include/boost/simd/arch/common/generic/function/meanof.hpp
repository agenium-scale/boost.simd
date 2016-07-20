//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_MEANOF_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_MEANOF_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/average.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_finite.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
//no overflow average for floating numbers

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( meanof_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    using result_type = A0;
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      A0 m = min(a0, a1);
      return if_else( bitwise_and(is_finite(a0), is_finite(a1)),//is_finite(a0) && is_finite(a1),
                      m + (max(a0, a1)-m)*Half<result_type>(),
                      average(a0, a1)
                    );
    }
  };
  BOOST_DISPATCH_OVERLOAD ( meanof_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::integer_<A0> >
                          , bd::generic_< bd::integer_<A0> >
                          )
  {
    using result_type = A0;
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      return (a0 & a1) + ((a0 ^ a1) >> 1);
    }
  };
} } }


#endif
