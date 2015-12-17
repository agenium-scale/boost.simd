//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MLOG10TWO2NMB_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MLOG10TWO2NMB_HPP_INCLUDED

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
    struct mlog10two2nmb_ : boost::dispatch::constant_value_<mlog10two2nmb_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mlog10two2nmb_,boost::dispatch::constant_value_<mlog10two2nmb_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0xc0dd8edeUL, 0xc02fe8bffd88220eULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mlog10two2nmb_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mlog10two2nmb_,mlog10two2nmb);
  }

  template<typename T> BOOST_FORCEINLINE auto Mlog10two2nmb() BOOST_NOEXCEPT
  -> decltype(functional::mlog10two2nmb( boost::dispatch::as_<T>{}))
  {
    return functional::mlog10two2nmb( boost::dispatch::as_<T>{} );
  }
} }

#endif
