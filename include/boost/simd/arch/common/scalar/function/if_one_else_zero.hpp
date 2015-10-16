//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/logical.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( if_one_else_zero_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< logical_<A0> >
                          )
  {
    using result_t = typename A0::value_type;
    BOOST_FORCEINLINE result_t operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return a0 ? One<result_t>() : Zero<result_t>() ;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( if_one_else_zero_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::fundamental_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return  A0(a0 != boost::simd::Zero<A0>());
    }
  };
} } }


#endif
