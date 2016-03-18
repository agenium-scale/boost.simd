//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_NOT_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_NOT_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing compare_not_equal capabilities

    Returns a logical scalar that is the result of the lexicographic
    test for != on elements of the entries,
    i.e. return @ref True if and only if two corresponding entries
    elements are not equal.

    It is probably not what you wish. Have a look to @ref is_not_equal

    @par Semantic:

    For every parameters of type T0:

    @code
    logical<scalar_of_t<T0>> r = compare_not_equal(x,y);
    @endcode

    is similar to:

    @code
    logical<scalar_of_t<T0>> r = any(x == y);
    @endcode

    @par Alias:
    @c compare_neq

    @see is_not_equal

  **/
  const boost::dispatch::functor<tag::compare_not_equal_> compare_not_equal = {};
} }
#endif

#include <boost/simd/function/scalar/compare_not_equal.hpp>
#include <boost/simd/function/simd/compare_not_equal.hpp>

#endif
