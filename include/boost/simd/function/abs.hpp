//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

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
    Function object implementing abs

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

    - Ensure for signed integers that the absolute value of @ref Valmin is
    @ref Valmin (thus negative!). This is a side effect of the 2-complements
    representation of integers. To avoid this, you may use the abs_s
    saturated functor or convert the input parameter to a larger type
    before taking the absolute value.

    - Abs is a also a standard library function name and there possible exists
    a C macro version which may be called instead of the boost simd version. 
    To avoid this you may either prefix abs, use the alias modulus or fabs.

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
