//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-trigonometric
    Function object implementing sinc capabilities

    Computes the sinus cardinal  value of its parameter that is sin(x)/x.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = sinc(x);
    @endcode

    is similar to:

    @code
    T r = x ? sin(x)/x : One;
    @endcode

    @see sin, sincpi, sinhc

  **/
  Value sinc(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/sinc.hpp>
#include <boost/simd/function/simd/sinc.hpp>

#endif
