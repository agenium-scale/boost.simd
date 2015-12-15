//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_ONEOSQRT5_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_ONEOSQRT5_HPP_INCLUDED

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
    struct oneosqrt5_ : boost::dispatch::constant_value_<oneosqrt5_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,oneosqrt5_,boost::dispatch::constant_value_<oneosqrt5_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3ee4f92eUL, 0x3fdc9f25c5bfedd9ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,oneosqrt5_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::oneosqrt5_,oneosqrt5);
  }

  template<typename T> BOOST_FORCEINLINE auto Oneosqrt5() BOOST_NOEXCEPT
  -> decltype(functional::oneosqrt5( boost::dispatch::as_<T>{}))
  {
    return functional::oneosqrt5( boost::dispatch::as_<T>{} );
  }
} }

#endif
