//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_DIV_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_DIV_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>
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

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, div_, boost::dispatch::elementwise_<div_>);
  }
  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, div_);
  }
  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::div_,div);
  }

  template < typename T>
  BOOST_FORCEINLINE T div(T const& a, T const& b )
  BOOST_NOEXCEPT
  {
    namespace bs = boost::simd;
    return bs::divides(a, b);
  }

  namespace bs = boost::simd;
  template < typename T, typename O>
  auto div(T const& a, T const& b, O const& )
    BOOST_NOEXCEPT_DECLTYPE(bs::divides(a, b, O()))
  {
    return bs::divides(a, b, O());
  }

#define BOOST_SIMD_DIV_WITH_OPTION(option)                      \
  template < typename T>                                        \
  BOOST_FORCEINLINE auto div(T const& a, T const& b             \
                         , boost::simd::tag::option##_ const& ) \
    BOOST_NOEXCEPT_DECLTYPE(bs::div##option(a, b))              \
  {                                                             \
    return bs::div##option(a, b);                               \
  }                                                             \
/**/

BOOST_SIMD_DIV_WITH_OPTION(ceil)
BOOST_SIMD_DIV_WITH_OPTION(fix)
BOOST_SIMD_DIV_WITH_OPTION(floor)
BOOST_SIMD_DIV_WITH_OPTION(round)
BOOST_SIMD_DIV_WITH_OPTION(round2even)

} }

#endif
