//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_GE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_GE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns a logical scalar that is the result of the lexicographic
    test for >= on all elements of the entries

    It is probably not what you wish. Have a look to is_greater_equal.

    This is a convenient alias of @ref compare_greater_equal
**/
  template<typename T> auto compare_ge(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns a logical scalar that is the result of the lexicographic
      test for >= on all elements of the entries


      Function object tied to simd::compare_ge

      @see simd::compare_ge
    **/
    const boost::dispatch::functor<tag::compare_ge_> compare_ge = {};
  }
} }
#endif

#include <boost/simd/function/definition/compare_ge.hpp>
#include <boost/simd/arch/common/scalar/function/compare_greater_equal.hpp>
#include <boost/simd/function/simd/compare_ge.hpp>

#endif
