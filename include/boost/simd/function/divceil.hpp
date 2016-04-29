//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVCEIL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVCEIL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing divceil capabilities

    Computes the ceil of the division of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = divceil(x, y);
    @endcode

    For floating point values the code is equivalent to:

    @code
    T r = ceil(x/y);
    @endcode

    for integral types, if y is null, it returns @ref Valmax (resp. @ref Valmin)
    if x is positive (resp. negative), and 0 if x is null.
    Take care also that dividing @ref Valmin by -1 for signed integral types has
    undefined behaviour.

    @see  divides, rec, divides_s, divfloor, divround, divround2even, divfix

  **/
  const boost::dispatch::functor<tag::divceil_> divceil = {};
} }
#endif

#include <boost/simd/function/scalar/divceil.hpp>
#include <boost/simd/function/simd/divceil.hpp>

#endif
