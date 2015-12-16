//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_EPS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_EPS_HPP_INCLUDED

#include <boost/simd/constant/definition/eps.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>

namespace boost { namespace simd
{
  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::eps_, eps);
} }

#endif

