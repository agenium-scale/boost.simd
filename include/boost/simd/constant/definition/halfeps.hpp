//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_HALFEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_HALFEPS_HPP_INCLUDED

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
    struct halfeps_ : boost::dispatch::constant_value_<halfeps_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,halfeps_,boost::dispatch::constant_value_<halfeps_>);
      BOOST_SIMD_REGISTER_CONSTANT(1, 0x33800000, 0x3CA0000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,halfeps_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::halfeps_,halfeps);
  }

  template<typename T> BOOST_FORCEINLINE auto Halfeps() BOOST_NOEXCEPT
  -> decltype(functional::halfeps( boost::dispatch::as_<T>{}))
  {
    return functional::halfeps( boost::dispatch::as_<T>{} );
  }
} }

#endif
