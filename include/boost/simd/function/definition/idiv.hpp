//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_IDIV_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_IDIV_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/function/definition/ceil.hpp>
#include <boost/simd/function/idivceil.hpp>
#include <boost/simd/function/definition/floor.hpp>
#include <boost/simd/function/idivfloor.hpp>
#include <boost/simd/function/definition/round.hpp>
#include <boost/simd/function/idivround.hpp>
#include <boost/simd/function/definition/round2even.hpp>
#include <boost/simd/function/idivround2even.hpp>
#include <boost/simd/function/definition/fix.hpp>
#include <boost/simd/function/idivfix.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, idiv_, boost::dispatch::elementwise_<idiv_>);
  }
  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, idiv_);
  }
  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::idiv_,idiv);
  }

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  template < typename T>
  BOOST_FORCEINLINE auto idiv(T const& a, T const& b )
    BOOST_NOEXCEPT_DECLTYPE(bs::idivfix(a, b))
  {
    return bs::idivfix(a, b);
  }

#define BOOST_SIMD_IDIV_WITH_OPTION(option)                      \
  template < typename T>                                         \
  BOOST_FORCEINLINE auto idiv(T const& a, T const& b             \
                             , bd::functor<bs::tag::option##_> const& ) \
    BOOST_NOEXCEPT_DECLTYPE(bs::idiv##option(a, b))              \
  {                                                              \
    return idiv##option(a, b);                                   \
  }                                                              \
/**/

BOOST_SIMD_IDIV_WITH_OPTION(ceil)
BOOST_SIMD_IDIV_WITH_OPTION(fix)
BOOST_SIMD_IDIV_WITH_OPTION(floor)
BOOST_SIMD_IDIV_WITH_OPTION(round)
BOOST_SIMD_IDIV_WITH_OPTION(round2even)

} }

#endif
