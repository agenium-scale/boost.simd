//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EPS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EPS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    This is the distance between x and the next representable value of the type.

    For floating types (except denormal numbers)  @c eps(x) returns 2^(exponent(x))*Eps


    @par Semantic:

    @code
    T r = eps(x);
    @endcode

    is similar to:

    @code

    if T is floating
      r = 2^(exponent(x))*Eps<T>()
    else if T is integral
      r = 1;
    @endcode

    @see ulp,  ulpdist,  Eps

    @return a value of same type as the input

**/
  template<typename T> auto eps(T const& x) {}


} }
#endif

#include <boost/simd/function/definition/eps.hpp>
#include <boost/simd/function/scalar/eps.hpp>
#include <boost/simd/function/simd/eps.hpp>

#endif
