//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_TRUE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_TRUE_HPP_INCLUDED
//TODO must return logical
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
    struct true_ : boost::dispatch::constant_value_<true_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,true_,boost::dispatch::constant_value_<true_>);
      BOOST_SIMD_REGISTER_CONSTANT(-1,0xFFFFFFFFU,0xFFFFFFFFFFFFFFFFUL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,true_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::true_,true);
  }

  template<typename T> BOOST_FORCEINLINE auto True() BOOST_NOEXCEPT
  -> decltype(functional::true( boost::dispatch::as_<T>{}))
  {
    return functional::true( boost::dispatch::as_<T>{} );
  }
} }

#endif
