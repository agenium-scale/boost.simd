//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing acsc capabilities

    inverse cosecant in radian.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acsc(x);
    @endcode

    is similar to:

    @code
    T r = asin(rec(x));
    @endcode

    @see acscd

  **/
  Value acsc(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/acsc.hpp>
#include <boost/simd/function/simd/acsc.hpp>

#endif
