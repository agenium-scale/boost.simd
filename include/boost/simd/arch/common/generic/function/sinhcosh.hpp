//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SINHCOSH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SINHCOSH_HPP_INCLUDED

#include <boost/fusion/include/std_pair.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( sinhcosh_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A0 & a2) const BOOST_NOEXCEPT
    {
      A0 a1;
      sinhcosh(a0, a1, a2);
      return a1;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( sinhcosh_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE  std::pair<A0, A0> operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 first, second;
      sinhcosh(a0, first, second);
      return {first, second};
    }
  };
} } }


#endif
