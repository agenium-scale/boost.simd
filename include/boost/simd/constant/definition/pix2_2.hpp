//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_PIX2_2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_PIX2_2_HPP_INCLUDED

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
    struct pix2_2_ : boost::dispatch::constant_value_<pix2_2_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,pix2_2_,boost::dispatch::constant_value_<pix2_2_>);
      BOOST_SIMD_REGISTER_CONSTANT(1, 0X38DAA000, 0X3DF0B4611A600000LL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,pix2_2_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::pix2_2_,pix2_2);
  }

  template<typename T> BOOST_FORCEINLINE auto Pix2_2() BOOST_NOEXCEPT
  -> decltype(functional::pix2_2( boost::dispatch::as_<T>{}))
  {
    return functional::pix2_2( boost::dispatch::as_<T>{} );
  }
} }

#endif
