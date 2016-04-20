//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 NumScale J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_ABS_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_ABS_S_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, abs_s_, boost::dispatch::elementwise_<abs_s_>);
  }
  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, abs_s_);
  }
  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::abs_s_,abs_s);

} }

#endif
