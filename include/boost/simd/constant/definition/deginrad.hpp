//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_DEGINRAD_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_DEGINRAD_HPP_INCLUDED

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
    struct deginrad_ : boost::dispatch::constant_value_<deginrad_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,deginrad_,boost::dispatch::constant_value_<deginrad_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0X3C8EFA35, 0X3F91DF46A2529D39LL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,deginrad_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::deginrad_,deginrad);
  }

  template<typename T> BOOST_FORCEINLINE auto Deginrad() BOOST_NOEXCEPT
  -> decltype(functional::deginrad( boost::dispatch::as_<T>{}))
  {
    return functional::deginrad( boost::dispatch::as_<T>{} );
  }
} }

#endif
