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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MODF_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MODF_HPP_INCLUDED

#include <boost/simd/function/scalar/trunc.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/fusion/include/std_pair.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( modf_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_ < bd::arithmetic_<A0> >
                          , bd::scalar_ < bd::arithmetic_<A0> >
                          , bd::scalar_ < bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 a0, A0 & frac,A0 & ent) const BOOST_NOEXCEPT
    {
      ent = simd::trunc(a0);
      frac = a0 - ent;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( modf_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_ < bd::arithmetic_<A0> >
                          , bd::scalar_ < bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0,A0 & ent) const BOOST_NOEXCEPT
    {
      A0 frac;
      simd::modf(a0,frac,ent);
      return frac;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( modf_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_ < bd::arithmetic_<A0> >
                          )
  {
    using result_t = std::pair<A0,A0>;
    BOOST_FORCEINLINE result_t operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      A0 first, second;
      boost::simd::modf(a0, first, second);
      return result_t(first, second);
    }
  };
} } }


#endif
