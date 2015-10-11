//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_INT_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_INT_SPLAT_HPP_INCLUDED
//TODO
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
    struct int_splat_ : boost::dispatch::constant_value_<int_splat_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,int_splat_,boost::dispatch::constant_value_<int_splat_>);
      BOOST_SIMD_REGISTER_CONSTANT(value);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,int_splat_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::int_splat_,int_splat);
  }

  template<typename T> BOOST_FORCEINLINE auto Int_splat() BOOST_NOEXCEPT
  -> decltype(functional::int_splat( boost::dispatch::as_<T>{}))
  {
    return functional::int_splat( boost::dispatch::as_<T>{} );
  }
} }

#endif
