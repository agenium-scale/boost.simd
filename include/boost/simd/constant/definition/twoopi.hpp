//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_TWOOPI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_TWOOPI_HPP_INCLUDED

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
    struct twoopi_ : boost::dispatch::constant_value_<twoopi_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,twoopi_,boost::dispatch::constant_value_<twoopi_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0X3F22F983, 0X3FE45F306DC9C883LL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,twoopi_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::twoopi_,twoopi);
  }

  template<typename T> BOOST_FORCEINLINE auto Twoopi() BOOST_NOEXCEPT
  -> decltype(functional::twoopi( boost::dispatch::as_<T>{}))
  {
    return functional::twoopi( boost::dispatch::as_<T>{} );
  }
} }

#endif
