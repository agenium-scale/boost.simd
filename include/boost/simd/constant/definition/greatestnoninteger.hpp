//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_GREATESTNONINTEGER_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_GREATESTNONINTEGER_HPP_INCLUDED

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
    struct greatestnoninteger_ : boost::dispatch::constant_value_<greatestnoninteger_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,greatestnoninteger_,boost::dispatch::constant_value_<greatestnoninteger_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x4affffffLL, 0x432fffffffffffffULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,greatestnoninteger_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::greatestnoninteger_,greatestnoninteger);
  }

  template<typename T> BOOST_FORCEINLINE auto Greatestnoninteger() BOOST_NOEXCEPT
  -> decltype(functional::greatestnoninteger( boost::dispatch::as_<T>{}))
  {
    return functional::greatestnoninteger( boost::dispatch::as_<T>{} );
  }
} }

#endif
