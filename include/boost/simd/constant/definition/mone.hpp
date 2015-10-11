//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MONE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MONE_HPP_INCLUDED

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
    struct mone_ : boost::dispatch::constant_value_<mone_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mone_,boost::dispatch::constant_value_<mone_>);
      BOOST_SIMD_REGISTER_CONSTANT(-1, 0xbf800000UL, 0xbff0000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mone_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mone_,mone);
  }

  template<typename T> BOOST_FORCEINLINE auto Mone() BOOST_NOEXCEPT
  -> decltype(functional::mone( boost::dispatch::as_<T>{}))
  {
    return functional::mone( boost::dispatch::as_<T>{} );
  }
} }

#endif
