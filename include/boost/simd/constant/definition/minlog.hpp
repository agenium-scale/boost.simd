//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MINLOG_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MINLOG_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct minlog_ : boost::dispatch::constant_value_<minlog_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,minlog_,boost::dispatch::constant_value_<minlog_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0xc2b0c0a5UL, 0xc086232bdd7abcd2ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,minlog_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::minlog_,minlog);
  }

  template<typename T> BOOST_FORCEINLINE auto Minlog() BOOST_NOEXCEPT
  -> decltype(functional::minlog( boost::dispatch::as_<T>{}))
  {
    return functional::minlog( boost::dispatch::as_<T>{} );
  }
} }

#endif
