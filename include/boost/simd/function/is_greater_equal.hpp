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
#ifndef BOOST_SIMD_FUNCTION_IS_GREATER_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GREATER_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according x is greater or equal to y or not.

    Infix notation can be used with operator '>='.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = is_greater_equal(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = x >= y;
    @endcode

    @par Alias:
    @c ge, @c is_ge

    @see  is_greater, is_gez, is_nge, is_ngez


    @return a logical value

**/
  template<typename T> auto is_greater_equal(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True or False according x is greater or equal to y or not.


      Function object tied to simd::is_greater_equal

      @see simd::is_greater_equal
    **/
    const boost::dispatch::functor<tag::is_greater_equal_> is_greater_equal = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_greater_equal.hpp>
#include <boost/simd/arch/common/scalar/function/is_greater_equal.hpp>
//#include <boost/simd/arch/common/function/simd/is_greater_equal.hpp>

#endif
