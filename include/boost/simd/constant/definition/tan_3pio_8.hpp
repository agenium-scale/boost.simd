//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_TAN_3PIO_8_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_TAN_3PIO_8_HPP_INCLUDED

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
    struct tan_3pio_8_ : boost::dispatch::constant_value_<tan_3pio_8_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,tan_3pio_8_,boost::dispatch::constant_value_<tan_3pio_8_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0X401A827AUL, 0X4003504F333F9DE6ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,tan_3pio_8_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::tan_3pio_8_,tan_3pio_8);
  }

  template<typename T> BOOST_FORCEINLINE auto Tan_3pio_8() BOOST_NOEXCEPT
  -> decltype(functional::tan_3pio_8( boost::dispatch::as_<T>{}))
  {
    return functional::tan_3pio_8( boost::dispatch::as_<T>{} );
  }
} }

#endif
