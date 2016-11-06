//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_STIRLING_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_STIRLING_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
 /*!
    @ingroup group-euler
    This function object computes stirling formula for the gamma function

    @par Semantic:
    For every parameter of floating type @c T , the following code:
    @code
    T r = stirling(x);
    @endcode
    computes  \f$\sqrt{2 \pi} x^{x-\frac12} e^{-x} ( 1 + \frac1{x} P(\frac1{x}))\f$,
    where \f$P\f$ is a polynomial.
    The formula implementation is usable for x between 33 and 172 to approximate \f$\Gamma(x)\f$.

    @see gamma, gammaln

    @param v0 value of a floating-point
    @return The aproximation of \f$\Gamma(v_0)\f$ using Striling's formula.
  **/
  Value stirling(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/stirling.hpp>
#include <boost/simd/function/simd/stirling.hpp>

#endif
