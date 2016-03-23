//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_GT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_GT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing compare_gt capabilities

    return a bool that is the result of the lexicographic
    test for > on all elements of the entries

    It is probably not what you wish. Have a look to @ref is_greater

    This is a convenient alias of @ref compare_greater
  **/
  const boost::dispatch::functor<tag::compare_gt_> compare_gt = {};
} }
#endif

#include <boost/simd/function/scalar/compare_greater.hpp>
#include <boost/simd/function/simd/compare_gt.hpp>

#endif
