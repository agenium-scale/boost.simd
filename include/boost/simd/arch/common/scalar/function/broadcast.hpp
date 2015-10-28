//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BROADCAST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_BROADCAST_HPP_INCLUDED

#include <boost/dispatch/adapted/std/integral_constant.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( broadcast_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_<bd::unspecified_<A0>>
                          , bd::constant_<bd::integer_<A1>>
                          )
  {
    using result_t = A0;
    static_assert(A1::value == 0
                 , "index out of range in scalar broadcast (!= 0)"
                 );

    BOOST_FORCEINLINE result_t operator() ( A0 a0, A1 const&) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };
} } }


#endif
