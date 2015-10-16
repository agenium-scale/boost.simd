//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 NumScale J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_BITWISE_CAST_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_BITWISE_CAST_INCLUDED

#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, bitwise_cast_, boost::dispatch::elementwise_<bitwise_cast_>);
  }
  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, bitwise_cast_);
  }
  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::bitwise_cast_,bitwise_cast);
  }
  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::bitwise_cast_,bitwise_cast);

  template < typename Target,  typename Arg >
  Target bitwise_cast(Arg&& arg)
  {
    return bitwise_cast(std::forward<Arg>(arg), boost::dispatch::as_<Target>{});
  }
} }

#endif
