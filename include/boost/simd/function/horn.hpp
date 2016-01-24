//==================================================================================================
/*!
  @file

  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_HORN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_HORN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes the horner value of its parameter.
    This is a static polynomial evaluation.

    @par Semantic

    For any value @c x of floating point type @c T,
    and any integral constants c0,  c1,  ..., cn representing floating point values
    bits in hexadecimal:

    @code
    T r = horn <T, c0, c1, c2, ...,  cn>(x);
    @endcode

    is equivalent to:

    @code
    T r = (C(n)*x+C(n-1))*x+C(n-2))*x+...+C(1))*x+C(0));
    @endcode

    where C(i) is Constant<T, ci>(),  that is the corresponding floating point value.

    This function evaluates the polynomial of degree n, whose increasing degrees
    coefficients are given by  C(0), C(1), ..., C(n) :

      \$f\sum_0^n C(i)x^i\f$

  **/
  template<typename T> auto horn(T const& x) {}

 } }
#endif

#include <boost/simd/function/scalar/horn.hpp>
#include <boost/simd/function/simd/horn.hpp>

#endif
