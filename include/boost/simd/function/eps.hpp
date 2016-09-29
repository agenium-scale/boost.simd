//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

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
    Computes the distance between its argument and the next representable value of its argument type.

    @par Semantic:

    For every parameter of type @c T

    @code
    T r = eps(x);
    @endcode

    is similar to:

    @code
    T  r = pow(2,exponent(x))*Eps<T>();
    @endcode

    if @c T is a floating-point type and to :

    @code
    T r = 1;
    @endcode

    if @c T is an integral type.

    @param  x Base value for epsilon computation.
    @return The distance between @c x and its next representable value.

    @see ulp, ulpdist, Eps
**/
  Value eps(Value const & x);

} }
#endif

#include <boost/simd/function/scalar/eps.hpp>
#include <boost/simd/function/simd/eps.hpp>

#endif
