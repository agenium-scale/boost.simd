//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_EXPX2C2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_EXPX2C2_HPP_INCLUDED

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
    struct expx2c2_ : boost::dispatch::constant_value_<expx2c2_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,expx2c2_,boost::dispatch::constant_value_<expx2c2_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3d000000UL, 0x3f80000000000000ull);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,expx2c2_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::expx2c2_,expx2c2);
  }

  template<typename T> BOOST_FORCEINLINE auto Expx2c2() BOOST_NOEXCEPT
  -> decltype(functional::expx2c2( boost::dispatch::as_<T>{}))
  {
    return functional::expx2c2( boost::dispatch::as_<T>{} );
  }
} }

#endif
