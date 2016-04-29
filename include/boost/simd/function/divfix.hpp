//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVFIX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVFIX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing divfix capabilities

    Computes the truncated division of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = divfix(x, y);
    @endcode

    The code is similar to:

    @code
    T r = trunc(x/y);
    @endcode

    for integral types, if y is @ref Zero, it returns @ref Valmax (resp. @ref Valmin)
    if x is positive (resp. negative) and @ref Zero if x is @ref Zero.
    Take also care that dividing @ref Valmin by -1 for signed integral types has
    undefined behaviour.

    @par Alias

    @c divtrunc

    @see  divides, rec, divides_s, divfloor,
    divround, divround2even

  **/
  const boost::dispatch::functor<tag::divfix_> divfix = {};
} }
#endif

#include <boost/simd/function/scalar/divfix.hpp>
#include <boost/simd/function/simd/divfix.hpp>

#endif
