//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_TWOTHIRD_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_TWOTHIRD_HPP_INCLUDED

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
    struct twothird_ : boost::dispatch::constant_value_<twothird_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,twothird_,boost::dispatch::constant_value_<twothird_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3f2aaaabUL, 0x3fe5555555555555ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,twothird_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::twothird_,twothird);
  }

  template<typename T> BOOST_FORCEINLINE auto Twothird() BOOST_NOEXCEPT
  -> decltype(functional::twothird( boost::dispatch::as_<T>{}))
  {
    return functional::twothird( boost::dispatch::as_<T>{} );
  }
} }

#endif
