//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_ONEO_120_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_ONEO_120_HPP_INCLUDED

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
    struct oneo_120_ : boost::dispatch::constant_value_<oneo_120_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,oneo_120_,boost::dispatch::constant_value_<oneo_120_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3c088889UL, 0x3f81111111111111ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,oneo_120_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::oneo_120_,oneo_120);
  }

  template<typename T> BOOST_FORCEINLINE auto Oneo_120() BOOST_NOEXCEPT
  -> decltype(functional::oneo_120( boost::dispatch::as_<T>{}))
  {
    return functional::oneo_120( boost::dispatch::as_<T>{} );
  }
} }

#endif
