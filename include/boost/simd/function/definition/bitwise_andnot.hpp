//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_BITWISE_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_BITWISE_ANDNOT_HPP_INCLUDED

#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, bitwise_andnot_, boost::dispatch::elementwise_<bitwise_andnot_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, bitwise_andnot_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::bitwise_andnot_,bitwise_andnot);
  }

  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::bitwise_andnot_, bitwise_andnot);

} }

#endif
