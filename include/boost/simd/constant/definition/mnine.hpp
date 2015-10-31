//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MNINE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MNINE_HPP_INCLUDED

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
    struct mnine_ : boost::dispatch::constant_value_<mnine_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mnine_,boost::dispatch::constant_value_<mnine_>);
      BOOST_SIMD_REGISTER_CONSTANT(-9, 0xc1100000UL, 0xc022000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mnine_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mnine_,mnine);
  }

  template<typename T> BOOST_FORCEINLINE auto Mnine() BOOST_NOEXCEPT
  -> decltype(functional::mnine( boost::dispatch::as_<T>{}))
  {
    return functional::mnine( boost::dispatch::as_<T>{} );
  }
} }

#endif
