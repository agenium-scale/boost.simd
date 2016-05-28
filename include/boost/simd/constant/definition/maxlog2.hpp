//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MAXLOG2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MAXLOG2_HPP_INCLUDED

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
    struct maxlog2_ : boost::dispatch::constant_value_<maxlog2_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,maxlog2_,boost::dispatch::constant_value_<maxlog2_>);
      BOOST_SIMD_REGISTER_CONSTANT( 0, 0x42fe0000UL, 0x408ff80000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,maxlog2_);
  }

  namespace detail
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::maxlog2_,maxlog2);
  }

  template<typename T> BOOST_FORCEINLINE auto Maxlog2()
  BOOST_NOEXCEPT_DECLTYPE(detail::maxlog2( boost::dispatch::as_<T>{}))
  {
    return detail::maxlog2( boost::dispatch::as_<T>{} );
  }
} }

#endif
