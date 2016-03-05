//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True or @ref False according x is greater than y or not.

    Infix notation can be used with operator '>'.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = is_greater(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = x > y;
    @endcode

    @par Alias:
    @c gt, @c is_gt

    @see  is_greater_equal, is_gtz, is_nle, is_nlez


    @return a logical value

**/
  template<typename T> auto is_greater(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True or @ref False according x is greater than y or not.


      Function object tied to simd::is_greater

      @see simd::is_greater
    **/
    const boost::dispatch::functor<tag::is_greater_> is_greater = {};
  }
} }
#endif

#include <boost/simd/function/scalar/is_greater.hpp>
#include <boost/simd/function/simd/is_greater.hpp>

#endif
