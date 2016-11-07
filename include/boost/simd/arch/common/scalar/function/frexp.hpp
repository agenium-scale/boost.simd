//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FREXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_FREXP_HPP_INCLUDED
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/tofloat.hpp>

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <utility>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( frexp_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE std::pair<A0,A0> operator() ( A0 a0) const BOOST_NOEXCEPT
    {
       A0 r0;
       using i_t = bd::as_integer_t<A0, signed>;
       i_t r1;
       std::tie(r0, r1) = ifrexp(a0);
       return {r0, tofloat(r1)};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( frexp_
                          , (typename A0)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE std::pair<A0,A0> operator() (const fast_tag &
                                                   , A0 a0 ) const BOOST_NOEXCEPT
    {
       A0 r0;
       using i_t = bd::as_integer_t<A0, signed>;
       i_t r1;
       std::tie(r0, r1) = fast_(ifrexp)(a0);
       return {r0, tofloat(r1)};
    }
  };
  BOOST_DISPATCH_OVERLOAD ( frexp_
                          , (typename A0)
                          , bd::cpu_
                          , boost::simd::std_tag
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE std::pair<A0,A0> operator() (const std_tag &,  A0 a0
                                                   ) const BOOST_NOEXCEPT
    {
      int e = 0;
      A0 r = std::frexp(a0, &e);
      return {r, A0(e)};
    }
  };
} } }


#endif
