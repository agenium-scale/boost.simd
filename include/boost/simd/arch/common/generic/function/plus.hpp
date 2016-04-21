//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_PLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_PLUS_HPP_INCLUDED

#include <boost/simd/detail/math.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/plus_s.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;

//   BOOST_DISPATCH_OVERLOAD ( plus_
//                           , (typename T)
//                           ,  bd::cpu_
//                           ,  bd::generic_<bd::fundamental_<T>>
//                           ,  bd::generic_<bd::fundamental_<T>>
//                           ,  bs::saturated_tag
//                           )
//   {
//     BOOST_FORCEINLINE T operator()(const T& a, const T& b
//                                   , const saturated_tag &) const BOOST_NOEXCEPT
//     {
//       return saturated_(plus)(a, b);
//     }
//   };
} } }

#endif
