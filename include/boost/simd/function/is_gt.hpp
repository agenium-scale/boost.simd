//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_GT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_gt capabilities

    Returns @ref True or @ref False according x is greater than y or not.

    Infix notation can be used with operator '>'.

    This is a convenient alias of @ref is_greater
  **/
  const boost::dispatch::functor<tag::is_gt_> is_gt = {};
} }
#endif

#include <boost/simd/function/scalar/is_greater.hpp>
#include <boost/simd/function/simd/is_gt.hpp>

#endif
