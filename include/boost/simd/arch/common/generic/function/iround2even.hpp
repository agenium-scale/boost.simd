//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_IROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_IROUND2EVEN_HPP_INCLUDED

#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/round2even.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( iround2even_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_<bd::integer_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };
  BOOST_DISPATCH_OVERLOAD ( iround2even_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_<bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0> operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return saturated_(toint)(round2even(a0));
    }
  };
  BOOST_DISPATCH_OVERLOAD ( iround2even_
                          , (typename A0)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::generic_<bd::integer_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0 const& a0
                                    ) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };
  BOOST_DISPATCH_OVERLOAD ( iround2even_
                          , (typename A0)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::generic_<bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0> operator() (const fast_tag &,  A0 const& a0
                                                      ) const BOOST_NOEXCEPT
    {
      return toint(round2even(a0));
    }
  };
} } }


#endif
