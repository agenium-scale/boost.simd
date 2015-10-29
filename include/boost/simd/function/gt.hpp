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
#ifndef BOOST_SIMD_FUNCTION_GT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according x is greater than y or not.

    Infix notation can be used with operator '>'.

    This is a convenient alias of is_greater
**/
  template<typename T> auto gt(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True or False according x is greater than y or not.


      Function object tied to simd::gt

      @see simd::gt
    **/
    const boost::dispatch::functor<tag::gt_> gt = {};
  }
} }
#endif

#include <boost/simd/function/definition/gt.hpp>
#include <boost/simd/arch/common/scalar/function/is_greater.hpp>
#include <boost/simd/function/simd/gt.hpp>

#endif
