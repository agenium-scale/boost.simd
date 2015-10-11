//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_EPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_EPS_HPP_INCLUDED

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
    struct eps_ : boost::dispatch::constant_value_<eps_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,eps_,boost::dispatch::constant_value_<eps_>);
      BOOST_SIMD_REGISTER_CONSTANT(1,0X34000000UL,0x3CB0000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,eps_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::eps_,eps);
  }

  template<typename T> BOOST_FORCEINLINE auto Eps() BOOST_NOEXCEPT
  -> decltype(functional::eps( boost::dispatch::as_<T>{}))
  {
    return functional::eps( boost::dispatch::as_<T>{} );
  }
} }

#endif
