//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing divs capabilities

    Computes  the truncated saturated division of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = divs(x, y);
    @endcode

    The code is similar to:

    @code
    T r = trunc(x/y);
    @endcode

    for integral types, if y is @ref Zero, it returns @ref Valmax (resp. @ref Valmin)
    if x is positive (resp. negative) and @ref Zero if x is @ref Zero.

    Saturated means that for signed integer types,
    @c divs(Valmin,-1) returns @ref Valmax.

    @par Alias

    @c rdivide

    @see  divides, rec, divfloor, divceil, divround, divround2even, divfix

  **/
  const boost::dispatch::functor<tag::divs_> divs = {};
} }
#endif

#include <boost/simd/function/scalar/divs.hpp>
#include <boost/simd/function/simd/divs.hpp>

#endif
