//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_TAN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_TAN_HPP_INCLUDED

#include <boost/simd/detail/enforce_precision.hpp>
#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/scalar/oneplus.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( tan_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bs::std_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0, std_tag const&) const BOOST_NOEXCEPT
    {
      return std::tan(a0);
    }
  };
} } }


#endif
