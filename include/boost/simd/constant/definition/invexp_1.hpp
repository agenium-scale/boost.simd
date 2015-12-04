//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_INVEXP_1_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_INVEXP_1_HPP_INCLUDED

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
    struct invexp_1_ : boost::dispatch::constant_value_<invexp_1_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,invexp_1_,boost::dispatch::constant_value_<invexp_1_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3ebc5ab2UL, 0x3fd78b56362cef38ull);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,invexp_1_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::invexp_1_,invexp_1);
  }

  template<typename T> BOOST_FORCEINLINE auto Invexp_1() BOOST_NOEXCEPT
  -> decltype(functional::invexp_1( boost::dispatch::as_<T>{}))
  {
    return functional::invexp_1( boost::dispatch::as_<T>{} );
  }
} }

#endif
