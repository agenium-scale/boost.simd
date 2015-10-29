//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_FACT_10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_FACT_10_HPP_INCLUDED

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
    struct fact_10_ : boost::dispatch::constant_value_<fact_10_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,fact_10_,boost::dispatch::constant_value_<fact_10_>);
      BOOST_SIMD_REGISTER_CONSTANT(3628800,0x4a5d7c00UL, 0x414baf8000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,fact_10_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::fact_10_,fact_10);
  }

  template<typename T> BOOST_FORCEINLINE auto Fact_10() BOOST_NOEXCEPT
  -> decltype(functional::fact_10( boost::dispatch::as_<T>{}))
  {
    return functional::fact_10( boost::dispatch::as_<T>{} );
  }
} }

#endif
