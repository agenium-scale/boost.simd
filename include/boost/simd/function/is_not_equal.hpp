//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-operator
    Function object implementing is_not_equal capabilities

    Returns @ref True if x and y are not equal else @ref False.
    Infix notation can be used with operator '!='.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = is_not_equal(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = x != y;
    @endcode

    @par Alias:
    @c ne, @c neq, @c is_neq

    @see  is_equal, is_nez, is_not_equal_with_equal_nans

  **/
  const boost::dispatch::functor<tag::is_not_equal_> is_not_equal = {};

} }
#endif

#include <boost/simd/function/scalar/is_not_equal.hpp>
#include <boost/simd/function/simd/is_not_equal.hpp>

#endif
