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
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_MODULUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_MODULUS_HPP_INCLUDED

#include <boost/simd/function/definition/abs.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::abs_,modulus);
  }

  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::abs_,modulus);
} }

#endif
