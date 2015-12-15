//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_LOG10_PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_LOG10_PI_HPP_INCLUDED

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
    struct log10_pi_ : boost::dispatch::constant_value_<log10_pi_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,log10_pi_,boost::dispatch::constant_value_<log10_pi_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3efe8a6eU, 0x3fdfd14db31ba3bbULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,log10_pi_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::log10_pi_,log10_pi);
  }

  template<typename T> BOOST_FORCEINLINE auto Log10_pi() BOOST_NOEXCEPT
  -> decltype(functional::log10_pi( boost::dispatch::as_<T>{}))
  {
    return functional::log10_pi( boost::dispatch::as_<T>{} );
  }
} }

#endif
