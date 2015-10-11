//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_ONEO_12_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_ONEO_12_HPP_INCLUDED

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
    struct oneo_12_ : boost::dispatch::constant_value_<oneo_12_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,oneo_12_,boost::dispatch::constant_value_<oneo_12_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3daaaaabUL, 0x3fb5555555555555ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,oneo_12_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::oneo_12_,oneo_12);
  }

  template<typename T> BOOST_FORCEINLINE auto Oneo_12() BOOST_NOEXCEPT
  -> decltype(functional::oneo_12( boost::dispatch::as_<T>{}))
  {
    return functional::oneo_12( boost::dispatch::as_<T>{} );
  }
} }

#endif
