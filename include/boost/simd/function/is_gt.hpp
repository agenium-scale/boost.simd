//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    Returns @ref True or @ref False according x is greater than y or not.

    Infix notation can be used with operator '>'.

    This is a convenient alias of @ref is_greater
**/
  template<typename T> auto is_gt(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True or @ref False according x is greater than y or not.


      Function object tied to simd::is_gt

      @see simd::is_gt
    **/
    const boost::dispatch::functor<tag::is_gt_> is_gt = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_gt.hpp>
#include <boost/simd/arch/common/scalar/function/is_greater.hpp>
#include <boost/simd/function/simd/is_gt.hpp>

#endif
