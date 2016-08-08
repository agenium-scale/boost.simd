//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOTH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOTH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-hyperbolic
    Function object implementing acoth capabilities

    Returns the hyperbolic cotangent argument \f$\frac12\log\frac{x^2+1}{x^2-1}\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acoth(x);
    @endcode

    is similar to:

    @code
    T r = Half<T>()*log(inc(sqr(x))/dec(sqr(x)));
    @endcode

    @see log, Half

  **/
  Value acoth(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/acoth.hpp>
#include <boost/simd/function/simd/acoth.hpp>

#endif
