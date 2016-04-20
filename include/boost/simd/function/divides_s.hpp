//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVIDES_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVIDES_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes  the truncated saturated division of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = divides_s(x, y);
    @endcode

    The code is similar to:

    @code
    T r = trunc(x/y);
    @endcode

    for integral types, if y is @ref Zero, it returns @ref Valmax (resp. @ref Valmin)
    if x is positive (resp. negative) and @ref Zero if x is @ref Zero.

    Saturated means that for signed integer types,
    @c divides_s(Valmin,-1) returns @ref Valmax.

    @par Alias

    @c rdivide

    @see  divides, rec, divfloor, divceil, divround, divround2even, divfix

    @return      a value of the same type as the input.


**/
  template<typename T> auto divides_s(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes  the truncated saturated division of its parameters.


      Function object tied to simd::divides_s

      @see simd::divides_s
    **/
    const boost::dispatch::functor<tag::divides_s_> divides_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/divides_s.hpp>
#include <boost/simd/function/simd/divides_s.hpp>

#endif
