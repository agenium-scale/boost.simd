//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVROUND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVROUND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing divround capabilities

    Computes the round of the division.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = divround(x, y);
    @endcode

    The code is similar to:

    @code
    T r = round(x/y);
    @endcode

    for integral types, if y is null, it returns @ref Valmax or @ref Valmin
    if x is positive (resp. negative) and 0 if x is null.
    Take also care that dividing @ref Valmin by -1 for signed integral types has
    undefined behaviour.

    @see  divides, rec, divides_s, divfloor,
    divceil, divround2even, divfix

  **/
  const boost::dispatch::functor<tag::divround_> divround = {};
} }
#endif

#include <boost/simd/function/scalar/divround.hpp>
#include <boost/simd/function/simd/divround.hpp>

#endif
