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
#ifndef BOOST_SIMD_FUNCTION_COMPARE_NEQ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_NEQ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns a logical scalar that is the result of the lexicographic
    test for != on elements of the entries,
    i.e. return true if and only if two corresponding entries
    elements are not equal.

    It is probably not what you wish. Have a look to <tt>is_not_equal</tt>

    This is a convenient alias of compare_not_equal
**/
  template<typename T> auto compare_neq(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns a logical scalar that is the result of the lexicographic
      test for != on elements of the entries,
      i.e. return true if and only if two corresponding entries
      elements are not equal.


      Function object tied to simd::compare_neq

      @see simd::compare_neq
    **/
    const boost::dispatch::functor<tag::compare_neq_> compare_neq = {};
  }
} }
#endif

#include <boost/simd/function/definition/compare_neq.hpp>
#include <boost/simd/arch/common/scalar/function/compare_not_equal.hpp>
#include <boost/simd/function/simd/compare_neq.hpp>

#endif
