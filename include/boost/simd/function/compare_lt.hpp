//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_LT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_LT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns a logical scalar that is the result of the lexicographic
    test for < on all elements of the entries

    It is probably not what you wish. Have a look to @ref is_less

    This is a convenient alias of @ref compare_less
**/
  template<typename T> auto compare_lt(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns a logical scalar that is the result of the lexicographic
      test for < on all elements of the entries


      Function object tied to simd::compare_lt

      @see simd::compare_lt
    **/
    const boost::dispatch::functor<tag::compare_lt_> compare_lt = {};
  }
} }
#endif

#include <boost/simd/function/scalar/compare_less.hpp>
#include <boost/simd/function/simd/compare_lt.hpp>

#endif
