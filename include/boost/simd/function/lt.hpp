//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing lt capabilities

    Returns True< or False according x is less than y or not.
   Infix notation can be used with operator '<'.

    This is a convenient alias of @ref is_less
  **/
  const boost::dispatch::functor<tag::lt_> lt = {};
} }
#endif

#include <boost/simd/function/scalar/is_less.hpp>
#include <boost/simd/function/simd/lt.hpp>

#endif
