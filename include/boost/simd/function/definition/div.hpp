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

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::div_,div);

//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   template < typename T>
//   BOOST_FORCEINLINE T div(T const& a, T const& b )
//   BOOST_NOEXCEPT
//   {
//     return bs::divides(a, b);
//   }

//   template < typename T, typename O>
//   auto div(T const& a, T const& b, O const& )
//     BOOST_NOEXCEPT_DECLTYPE(bs::divides(a, b, O()))
//   {
//     return bs::divides(a, b, O());
//   }

// #define BOOST_SIMD_DIV_WITH_OPTION(option)                      \
//   template < typename T>                                        \
//   BOOST_FORCEINLINE auto div(T const& a, T const& b             \
//                          , bd::functor<bs::tag::option##_> const& ) \
//     BOOST_NOEXCEPT_DECLTYPE(bs::div##option(a, b))              \
//   {                                                             \
//     return bs::div##option(a, b);                               \
//   }                                                             \
// /**/

// BOOST_SIMD_DIV_WITH_OPTION(ceil)
// BOOST_SIMD_DIV_WITH_OPTION(fix)
// BOOST_SIMD_DIV_WITH_OPTION(floor)
// BOOST_SIMD_DIV_WITH_OPTION(round)
// BOOST_SIMD_DIV_WITH_OPTION(round2even)

} }

#endif
