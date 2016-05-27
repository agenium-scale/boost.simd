//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_COMMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_COMMA_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( comma_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_<bd::unspecified_<A0> >
                          , bd::generic_<bd::unspecified_<A1> >
                          )
  {
    BOOST_FORCEINLINE A1 operator() (const A0&, const A1& a1) const BOOST_NOEXCEPT
    {
      return a1;
    }
  };
} } }


#endif
