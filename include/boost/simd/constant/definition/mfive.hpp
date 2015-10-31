//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MFIVE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MFIVE_HPP_INCLUDED

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
    struct mfive_ : boost::dispatch::constant_value_<mfive_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mfive_,boost::dispatch::constant_value_<mfive_>);
      BOOST_SIMD_REGISTER_CONSTANT(-5, 0xc0a00000UL,0xc014000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mfive_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mfive_,mfive);
  }

  template<typename T> BOOST_FORCEINLINE auto Mfive() BOOST_NOEXCEPT
  -> decltype(functional::mfive( boost::dispatch::as_<T>{}))
  {
    return functional::mfive( boost::dispatch::as_<T>{} );
  }
} }

#endif
