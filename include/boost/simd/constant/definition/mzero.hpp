//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MZERO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MZERO_HPP_INCLUDED

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
    struct mzero_ : boost::dispatch::constant_value_<mzero_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mzero_,boost::dispatch::constant_value_<mzero_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x80000000UL, 0x8000000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mzero_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mzero_,mzero);
  }

  template<typename T> BOOST_FORCEINLINE auto Mzero() BOOST_NOEXCEPT
  -> decltype(functional::mzero( boost::dispatch::as_<T>{}))
  {
    return functional::mzero( boost::dispatch::as_<T>{} );
  }
} }

#endif
