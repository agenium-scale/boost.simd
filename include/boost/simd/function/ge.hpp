//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing ge capabilities

    Returns True or False according x is greater or equal to y or not.

    Infix notation can be used with operator '>='.

    This is a convenient alias of @ref is_greater_equal
  **/
  const boost::dispatch::functor<tag::ge_> ge = {};
} }
#endif

#include <boost/simd/function/scalar/is_greater_equal.hpp>
#include <boost/simd/function/simd/ge.hpp>

#endif
