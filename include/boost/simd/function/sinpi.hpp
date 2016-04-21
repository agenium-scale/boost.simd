//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing sinpi capabilities

    sine of angle in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = sinpi(x);
    @endcode

    is similar to:

    @code
    T r = sin(Pi<T>()*x);
    @endcode

    @see sine, sincospi, sin, sind

  **/
  const boost::dispatch::functor<tag::sinpi_> sinpi = {};
} }
#endif

#include <boost/simd/function/scalar/sinpi.hpp>
#include <boost/simd/function/simd/sinpi.hpp>

#endif
