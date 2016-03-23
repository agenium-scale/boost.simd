//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPONENTBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPONENTBITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing exponentbits capabilities

    Returns the exponent bits of the floating input as an integer value,
    the other bits (sign and mantissa) being just masked.

    This function is not defined on integral types.

    @par Semantic:

    @code
    as_integer_t<T> r = exponentbits(x);
    @endcode

    is similar to

    @code
    as_integer_t<T> r = x&Exponentmask<T>();
    @endcode

  **/
  const boost::dispatch::functor<tag::exponentbits_> exponentbits = {};
} }
#endif

#include <boost/simd/function/scalar/exponentbits.hpp>
#include <boost/simd/function/simd/exponentbits.hpp>

#endif
