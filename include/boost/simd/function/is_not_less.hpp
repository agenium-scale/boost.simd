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
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_LESS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_LESS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    TODO Put description here

    @par Semantic:

    @code
    as_logical_t<T> r = is_not_less(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = !(x < y);
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to @c is_greater_equal(x, y)
    for floating types

    @par Alias:

    @c is_nlt



    @return a logical value

**/
  template<typename T> auto is_not_less(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      TODO Put description here


      Function object tied to simd::is_not_less

      @see simd::is_not_less
    **/
    const boost::dispatch::functor<tag::is_not_less_> is_not_less = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_not_less.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_less.hpp>
//#include <boost/simd/arch/common/function/simd/is_not_less.hpp>

#endif
