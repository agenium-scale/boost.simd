//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_TWO_SPLIT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_TWO_SPLIT_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/detail/enforce_precision.hpp>
#include <boost/simd/constant/splitfactor.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/minus.hpp>
#include <utility>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( two_split_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE
      A0 operator() ( A0 const& a0,A0& a2) const BOOST_NOEXCEPT
    {
      A0 a1;
      boost::simd::two_split(a0, a1, a2);
      return a1;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( two_split_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    using result_t = std::pair<A0,A0>;                                 ;
    BOOST_FORCEINLINE result_t operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 first, second;
      boost::simd::two_split( a0, first, second );
      return result_t(first, second);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( two_split_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 const& a, A0 & r0,A0 & r1) const BOOST_NOEXCEPT
    {
      detail::enforce_precision<A0> enforcer;
      A0 const c = Splitfactor<A0>()*a;
      A0 const c1 = c-a;
      r0 = c-c1;
      r1 = a-r0;
    }
  };
} } }


#endif
