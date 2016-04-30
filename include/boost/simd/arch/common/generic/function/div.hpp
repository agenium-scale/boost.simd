//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_DIV_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_DIV_HPP_INCLUDED

#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/definition/ceil.hpp>
#include <boost/simd/function/divceil.hpp>
#include <boost/simd/function/definition/floor.hpp>
#include <boost/simd/function/divfloor.hpp>
#include <boost/simd/function/definition/round.hpp>
#include <boost/simd/function/divround.hpp>
#include <boost/simd/function/definition/round2even.hpp>
#include <boost/simd/function/divround2even.hpp>
#include <boost/simd/function/definition/fix.hpp>
#include <boost/simd/function/divfix.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{

  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::arithmetic_<T>>
                          , bd::generic_<bd::arithmetic_<T>>
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
                          , bd::generic_<bd::arithmetic_<T>>
                          , bd::generic_<bd::arithmetic_<T>>
                          , bs::tag::ceil_
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a, T const& b
                                  , bd::functor<bs::tag::ceil_> const& ) const BOOST_NOEXCEPT
    {
      return divceil(a, b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::arithmetic_<T>>
                          , bd::generic_<bd::arithmetic_<T>>
                          , bs::tag::floor_
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a, T const& b
                                  ,  bd::functor<bs::tag::floor_> const& ) const BOOST_NOEXCEPT
    {
      return divfloor(a, b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::arithmetic_<T>>
                          , bd::generic_<bd::arithmetic_<T>>
                          , bs::tag::fix_
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a, T const& b
                                  ,  bd::functor<bs::tag::fix_> const& ) const BOOST_NOEXCEPT
    {
      return divfix(a, b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::arithmetic_<T>>
                          , bd::generic_<bd::arithmetic_<T>>
                          , bs::tag::round_
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a, T const& b
                                  ,  bd::functor<bs::tag::round_> const& ) const BOOST_NOEXCEPT
    {
      return divround(a, b);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( div_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::arithmetic_<T>>
                          , bd::generic_<bd::arithmetic_<T>>
                          , bs::tag::round2even_
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a, T const& b
                                  ,  bd::functor<bs::tag::round2even_> const& ) const BOOST_NOEXCEPT
    {
      return divround2even(a, b);
    }
  };

} } }

#endif
