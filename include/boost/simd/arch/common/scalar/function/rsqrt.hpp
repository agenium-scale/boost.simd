//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_RSQRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_RSQRT_HPP_INCLUDED
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/fast.hpp>

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_OVERLOAD ( rsqrt_
                          , (typename A0)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::scalar_< bd::single_<A0> >
                         )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0 a0) const BOOST_NOEXCEPT
    {
      typedef bd::as_integer_t<A0> i_t;

      // Quake III Arena RSQRT approximation
      i_t x = bitwise_cast<i_t>(a0);
      i_t y = 0x5f3759df - (x >> 1);

      // make negative values be NaN
      y |= x >> (sizeof(i_t)*CHAR_BIT-1);

      A0 x2 = a0 * 0.5f;
      A0 y2 = bitwise_cast<A0>(y);

      // Newton-Rhapson refinement steps: 2 NR steps for precision purpose
      y2    = y2 * ( 1.5f - ( x2 * y2 * y2 ) );
      return  y2 * ( 1.5f - ( x2 * y2 * y2 ) );
    }
  };
  BOOST_DISPATCH_OVERLOAD ( rsqrt_
                          , (typename A0)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::scalar_< bd::double_<A0> >
                         )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0 a0) const BOOST_NOEXCEPT
    {
      return simd::rsqrt(a0);
    }
  };

} } }


#endif
