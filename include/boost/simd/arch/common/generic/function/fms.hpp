//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_FMS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_FMS_HPP_INCLUDED

#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( fms_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::unspecified_<A0> >
                          , bd::generic_< bd::unspecified_<A0> >
                          , bd::generic_< bd::unspecified_<A0> >
                                    )
  {
    BOOST_FORCEINLINE
      A0 operator() ( A0 const& a0, A0 const& a1, A0 const& a2) const BOOST_NOEXCEPT
    {
      return minus(multiplies(a0, a1), a2);
    }
  };
} } }


#endif
