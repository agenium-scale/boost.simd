//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_EQ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_EQ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns a logical scalar value that is the result of the lexicographic
    test for equality of all elements of the entries,
    i.e. return @ref True if and only if all corresponding entries
    elements are equal.

    It is probably not what you wish. Have a look to @ref is_equal

    This is a convenient alias of @ref compare_equal
**/
  template<typename T> auto compare_eq(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns a logical scalar value that is the result of the lexicographic
      test for equality of all elements of the entries,
      i.e. return @ref True if and only if all corresponding entries
      elements are equal.


      Function object tied to simd::compare_eq

      @see simd::compare_eq
    **/
    const boost::dispatch::functor<tag::compare_eq_> compare_eq = {};
  }
} }
#endif

#include <boost/simd/function/scalar/compare_equal.hpp>
#include <boost/simd/function/simd/compare_eq.hpp>

#endif
