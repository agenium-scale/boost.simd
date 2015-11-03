//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns a logical scalar value that is the result of the lexicographic
    test for equality of all elements of the entries,
    i.e. return @ref True if and only if all corresponding entries
    elements are equal.

    It is probably not what you wish. Have a look to <tt>is_equal</tt>

    @par Semantic:

    For every parameters of type T0:

    @code
    logical<scalar_of_t<T0>> r = compare_equal(x,y);
    @endcode

    is similar to:

    @code
    logical<scalar_of_t<T0>> r = all(x == y)
    @endcode

    @par Alias:
    @c compare_eq

    @see is_equal


    @return a value of the scalar logical type asssociated to the parameters

**/
  template<typename T> auto compare_equal(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns a logical scalar value that is the result of the lexicographic
      test for equality of all elements of the entries,
      i.e. return @ref True if and only if all corresponding entries
      elements are equal.


      Function object tied to simd::compare_equal

      @see simd::compare_equal
    **/
    const boost::dispatch::functor<tag::compare_equal_> compare_equal = {};
  }
} }
#endif

#include <boost/simd/function/definition/compare_equal.hpp>
#include <boost/simd/arch/common/scalar/function/compare_equal.hpp>
#include <boost/simd/function/simd/compare_equal.hpp>

#endif
