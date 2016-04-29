//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ABS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-arithmetic
    Function object implementing abs capabilities

    Computes the absolute value of its parameter.

    @par Semantic

    For any value @c x of type @c T,

    @code
    T r = abs(x);
    @endcode

    is equivalent to:

    @code
    T r = x < T(0) ? -x : x;
    @endcode

    @par Note:

    - Take care that for signed integers the absolute value of @ref Valmin is
    @ref Valmin (thus negative!). This is a side effect of the 2-complement
    representation of integers. To avoid this, you can use the abs_s
    saturated functor or convert the input parameter to a larger type
    before taking the absolute value.

    - Also abs is a very current function name and sometimes a C macro version can be
    an unwanted concurrent of simd::abs, you can just prefix abs or
    use the alias modulus or fabs instead to circumvent this problem.

    @par Alias

    modulus, fabs

    @par Decorators

    std_ for floating entries

    @see  abs_s, sqr_abs, sqr_ss

  **/
  const boost::dispatch::functor<tag::abs_> abs = {};
} }
#endif

#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/simd/abs.hpp>

#endif
