//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TOINT_HPP_INCLUDED
#include <boost/simd/function/fast.hpp>

#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( toint_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::integer_<A0> >
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0, signed> operator() ( A0  a0) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };
  BOOST_DISPATCH_OVERLOAD ( toint_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0, signed>;
    BOOST_FORCEINLINE result_t operator() ( A0  a0) const BOOST_NOEXCEPT
    {
      return result_t(a0);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( toint_
                          , (typename A0)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::scalar_< bd::unspecified_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0, signed>;
    BOOST_FORCEINLINE result_t operator() (const fast_tag &,  A0 const& a0
                                          ) const BOOST_NOEXCEPT
    {
      return toint(a0);
    }
  };
} } }


#endif
