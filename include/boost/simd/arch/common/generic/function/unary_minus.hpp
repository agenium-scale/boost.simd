//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_UNARY_MINUS_HPP_INCLUDED

#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( unary_minus_
                          , (typename T)
                          , bd::cpu_
                          , bs::saturated_tag
                          , bd::generic_<bd::signed_<T>>
                           )
  {
    BOOST_FORCEINLINE T operator()(const saturated_tag &, T const& a0) const BOOST_NOEXCEPT
    {
      return if_else(a0 == Valmin<T>(),Valmax<T>(),bs::unary_minus(a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( unary_minus_
                          , (typename T)
                          , bd::cpu_
                          , bs::saturated_tag
                          , bd::generic_<bd::unspecified_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(const saturated_tag &, T const& a) const BOOST_NOEXCEPT
    {
      return unary_minus(a);
    }
  };
} } }

#endif
