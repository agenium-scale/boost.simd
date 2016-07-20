//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FREXP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FREXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing frexp capabilities

    Computes a mantissa and an exponent pair for the input

    @code
    std::tie(m, e)= frexp(x);
    @endcode

    is similar to:

    @code
    as_integer_t<T> e = exponent(x)+1;
    T m = mantissa(x)/2;
    @endcode

    The call

    @code
    std:pair<T,as_integer_t<T>> p = frexp(x);
    @endcode

    can also be used.

    @par Note:

    @c frexp splits a floating point value @c v f in a signed mantissa @c m and
    an exponent @c e so that:  @f$v = m\times 2^e@f$, with absolute value of @c m
    between 0.5 (included) and 1 (excluded)

    Take care that these results differ from the returns of the functions @ref mantissa
    and @ref exponent

    The decorators fast_ and std_ can be used.

    fast_ provides a speedier call but limiting values as Nan or Inf are not handled properly.
    std_ transmit the call to std::frexp. That implies that simd is ever emulated.
    @see exponent,  mantissa

  **/
  const boost::dispatch::functor<tag::frexp_> frexp = {};
} }
#endif

#include <boost/simd/function/scalar/frexp.hpp>
#include <boost/simd/function/scalar/frexp.hpp>
#include <boost/simd/function/simd/frexp.hpp>

#endif
