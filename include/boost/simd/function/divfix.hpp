//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    for integral types, if y is null, it returns Valmax (resp. Valmin)
    if x is positive (resp. negative) and 0 if x is null.
    Take also care that dividing Valmin by -1 for signed integral types has
    undefined behaviour.

    @par Alias

    @c divtrunc

    @see  divides, rec, divs, divfloor,
    divround, divround2even

    @return      a value of the same type as the input.


**/
  template<typename T> auto divfix(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the truncated division of its parameters.


      Function object tied to simd::divfix

      @see simd::divfix
    **/
    const boost::dispatch::functor<tag::divfix_> divfix = {};
  }
} }
#endif

#include <boost/simd/function/definition/divfix.hpp>
#include <boost/simd/arch/common/scalar/function/divfix.hpp>
#include <boost/simd/function/simd/divfix.hpp>

#endif
