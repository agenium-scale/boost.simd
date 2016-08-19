//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

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
    Function object implementing eps capabilities

    This is the distance between x and the next representable value of x's type.

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
  Value eps(Value const & v0);

} }
#endif

#include <boost/simd/function/scalar/eps.hpp>
#include <boost/simd/function/simd/eps.hpp>

#endif
