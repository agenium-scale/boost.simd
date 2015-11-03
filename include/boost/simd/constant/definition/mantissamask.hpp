//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MANTISSAMASK_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MANTISSAMASK_HPP_INCLUDED

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
    struct mantissamask_ : boost::dispatch::constant_value_<mantissamask_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mantissamask_,boost::dispatch::constant_value_<mantissamask_>);
      BOOST_SIMD_REGISTER_CONSTANT(0,0x807FFFFFUL,0x800FFFFFFFFFFFFFULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mantissamask_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mantissamask_,mantissamask);
  }

  template<typename T> BOOST_FORCEINLINE auto Mantissamask() BOOST_NOEXCEPT
  -> decltype(functional::mantissamask( boost::dispatch::as_<T>{}))
  {
    return functional::mantissamask( boost::dispatch::as_<T>{} );
  }
} }

#endif
