//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_less capabilities

    Returns  @ref True or @ref False according x is less than y or not.
   Infix notation can be used with operator '<'.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = is_less(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = x < y;
    @endcode

    @par Alias:
    @c lt, @c is_lt

    @see  is_less_equal, is_ltz, is_nge, is_nge

  **/
  as_logical_t<Value> is_less(Value const& x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/is_less.hpp>
#include <boost/simd/function/simd/is_less.hpp>

#endif
