//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_UNARY_MINUS_HPP_INCLUDED

#include <boost/simd/function/unary_minus_s.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>


namespace boost { namespace simd { namespace ext
{

//   BOOST_DISPATCH_OVERLOAD ( unary_minus_
//                           , (typename T)
//                           ,  bd::cpu_
//                           ,  bs::saturated_tag
//                           ,  bd::generic_<bd::fundamental_<T>>
//                           )
//   {
//     BOOST_FORCEINLINE T operator()(const saturated_tag &, const T& a
//                                   ) const BOOST_NOEXCEPT
//     {
//       return unary_minus_s(a);
//     }
//   };
} } }


#endif
