//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    @return      a value of the same type as the input.


**/
  template<typename T> auto divs(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes  the truncated saturated division of its parameters.


      Function object tied to simd::divs

      @see simd::divs
    **/
    const boost::dispatch::functor<tag::divs_> divs = {};
  }
} }
#endif

#include <boost/simd/function/definition/divs.hpp>
#include <boost/simd/arch/common/scalar/function/divs.hpp>
#include <boost/simd/function/simd/divs.hpp>

#endif
