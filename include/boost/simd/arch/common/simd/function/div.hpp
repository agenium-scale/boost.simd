//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIV_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIV_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/divides.hpp>
#include <boost/simd/arch/common/simd/function/divceil.hpp>
#include <boost/simd/arch/common/simd/function/divfloor.hpp>
#include <boost/simd/arch/common/simd/function/divround.hpp>
#include <boost/simd/arch/common/simd/function/divround2even.hpp>
#include <boost/simd/arch/common/simd/function/divfix.hpp>

namespace boost { namespace simd { namespace ext
{

  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<T>, X>
                          , bs::pack_<bd::arithmetic_<T>, X>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a, T const& b ) const BOOST_NOEXCEPT
    {
      return divides(a, b);
    }
  };

} } }

#endif
