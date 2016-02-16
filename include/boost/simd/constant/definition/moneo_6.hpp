//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MONEO_6_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MONEO_6_HPP_INCLUDED

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
    struct moneo_6_ : boost::dispatch::constant_value_<moneo_6_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,moneo_6_,boost::dispatch::constant_value_<moneo_6_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0xBE2AAAABUL, 0xBFC5555555555555LL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,moneo_6_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::moneo_6_,moneo_6);
  }

  template<typename T> BOOST_FORCEINLINE auto Moneo_6()
  BOOST_NOEXCEPT_DECLTYPE(detail::moneo_6( boost::dispatch::as_<T>{}))
  {
    return detail::moneo_6( boost::dispatch::as_<T>{} );
  }
} }

#endif
