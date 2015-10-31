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
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_LESS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_LESS_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-predicates

    Returns @ref True  or @ref False depending on whether x is
    not less or equal to y or is.

    @par Semantic:

    @code
    as_logical_t<T> r = is_not_less_equal(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = !(x <= y);
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to a call to @ref is_greater
    for floating types

    @par Alias:

    @c is_nle



    @return a logical value

**/
  template<typename T> auto is_not_less_equal(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True  or @ref False depending on whether x is
      not less or equal to y or is.

    @par Semantic:


      Function object tied to simd::is_not_less_equal

      @see simd::is_not_less_equal
    **/
    const boost::dispatch::functor<tag::is_not_less_equal_> is_not_less_equal = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_not_less_equal.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_less_equal.hpp>
#include <boost/simd/function/simd/is_not_less_equal.hpp>

#endif
