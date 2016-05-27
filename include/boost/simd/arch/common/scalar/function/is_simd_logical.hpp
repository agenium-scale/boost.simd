//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED

#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/simd/function/scalar/genmask.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( is_simd_logical_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_<bd::integer_<A0> >
                          )
  {
    BOOST_FORCEINLINE logical<A0> operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return a0 ==  genmask(a0);
    }
  };
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( is_simd_logical_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_<bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE logical<A0> operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      using i_t = bd::as_integer_t<A0>;
      return is_simd_logical(bitwise_cast<i_t>(a0)).value();
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_simd_logical_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_<logical_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 ) const BOOST_NOEXCEPT
    {
      return {true};
    }
  };
} } }


#endif
