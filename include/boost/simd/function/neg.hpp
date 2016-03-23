//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing neg capabilities

    return the elementwise unary minus of the parameter

    Infix notation can be used with operator '-'

    This is a convenient alias of @ref unary_minus
  **/
  const boost::dispatch::functor<tag::neg_> neg = {};
} }
#endif

#include <boost/simd/function/scalar/unary_minus.hpp>
#include <boost/simd/function/simd/neg.hpp>

#endif
