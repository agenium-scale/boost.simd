//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_TWOPI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_TWOPI_HPP_INCLUDED

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
    struct twopi_ : boost::dispatch::constant_value_<twopi_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,twopi_,boost::dispatch::constant_value_<twopi_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0X40C90FDB, 0X401921FB54442D18LL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,twopi_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::twopi_,twopi);
  }

  template<typename T> BOOST_FORCEINLINE auto Twopi() BOOST_NOEXCEPT
  -> decltype(functional::twopi( boost::dispatch::as_<T>{}))
  {
    return functional::twopi( boost::dispatch::as_<T>{} );
  }
} }

#endif
