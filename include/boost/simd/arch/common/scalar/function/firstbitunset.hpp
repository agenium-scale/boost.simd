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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FIRSTBITUNSET_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FIRSTBITUNSET_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( firstbitunset_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          )
  {
    bd::as_integer_t<A0, unsigned> operator() ( A0 a0) const
    {
      return ~a0 & (a0+One<A0>());
    }
  };

  BOOST_DISPATCH_OVERLOAD ( firstbitunset_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    using result_type = bd::as_integer_t<A0, unsigned>;
    result_type operator() ( A0 a0) const
    {
      return firstbitunset(bitwise_cast<result_type>(a0));
    }
  };
} } }


#endif
