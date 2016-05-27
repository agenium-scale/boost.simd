//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SQRT1PM1_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SQRT1PM1_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/minusone.hpp>
#include <boost/simd/function/oneplus.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( sqrt1pm1_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 tmp =  bs::sqrt(oneplus(a0));
      return  bs::if_else((bs::abs(a0) < bs::Half<A0>()),
                          a0/bs::oneplus(tmp),
                          bs::minusone(tmp));
    }
  };
} } }


#endif
