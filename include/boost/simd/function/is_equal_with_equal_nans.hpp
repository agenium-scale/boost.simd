//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_equal_with_equal_nans capabilities

    Returns @ref True or @ref False according x and y are equal or not.
    Nans are considered equal

    @par Semantic:

    @code
    as_logical_t<T> r = is_equal_with_equal_nans(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = (x == y) || ((x!= x) && (y!= y));
    @endcode

    @see Nan

  **/
  const boost::dispatch::functor<tag::is_equal_with_equal_nans_> is_equal_with_equal_nans = {};
} }
#endif

#include <boost/simd/function/scalar/is_equal_with_equal_nans.hpp>
#include <boost/simd/function/simd/is_equal_with_equal_nans.hpp>

#endif
