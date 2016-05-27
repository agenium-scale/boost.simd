//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MAXFLINT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MAXFLINT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct maxflint_ : boost::dispatch::constant_value_<maxflint_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,maxflint_,boost::dispatch::constant_value_<maxflint_>);
      BOOST_SIMD_REGISTER_CONSTANT(1, 0x4b800000, 0x4340000000000000ll);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,maxflint_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::maxflint_,maxflint);
  }

  template<typename T> BOOST_FORCEINLINE auto Maxflint()
  BOOST_NOEXCEPT_DECLTYPE(detail::maxflint( boost::dispatch::as_<T>{}))
  {
    return detail::maxflint( boost::dispatch::as_<T>{} );
  }
} }

#endif
