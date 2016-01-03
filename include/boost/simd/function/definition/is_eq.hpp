//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_IS_EQ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_IS_EQ_HPP_INCLUDED

#include <boost/simd/function/definition/is_equal.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    using is_eq_ = is_equal_;
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::is_eq_,is_eq);
  }
  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::is_eq_,is_eq);
} }

#endif
