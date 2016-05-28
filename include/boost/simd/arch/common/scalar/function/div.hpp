//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIV_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIV_HPP_INCLUDED

#include <boost/simd/function/scalar/divides.hpp>
#include <boost/simd/function/definition/fix.hpp>
#include <boost/simd/function/definition/ifix.hpp>
#include <boost/simd/arch/common/scalar/function/divceil.hpp>
#include <boost/simd/arch/common/scalar/function/divfloor.hpp>
#include <boost/simd/arch/common/scalar/function/divround.hpp>
#include <boost/simd/arch/common/scalar/function/divround2even.hpp>
#include <boost/simd/arch/common/scalar/function/divtrunc.hpp>
// #include <boost/simd/arch/common/generic/function/idivceil.hpp>
// #include <boost/simd/arch/common/generic/function/idivfloor.hpp>
// #include <boost/simd/arch/common/generic/function/idivround.hpp>
// #include <boost/simd/arch/common/generic/function/idivround2even.hpp>
// #include <boost/simd/arch/common/generic/function/idivfix.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/hierarchy.hpp>
//#include <boost/simd/function/fast.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{

  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bd::scalar_<bd::arithmetic_<T>>
                          , bd::scalar_<bd::arithmetic_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a, T const& b ) const BOOST_NOEXCEPT
    {
      return divides(a, b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bs::tag::fix_
                          , bd::scalar_<bd::arithmetic_<T>>
                          , bd::scalar_<bd::arithmetic_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()( bd::functor<bs::tag::fix_> const&
                                  , T const& a, T const& b ) const BOOST_NOEXCEPT
    {
      return div(bs::trunc, a, b);
    }
  };

} } }

#endif
