//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATANPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATANPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing atanpi capabilities

    inverse tangent in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = atanpi(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[-0.5, 0.5[\f$ such that <tt>tanpi(r) == x</tt>.

    @see atan2, atan2d, atand, atan

  **/
  const boost::dispatch::functor<tag::atanpi_> atanpi = {};
} }
#endif

#include <boost/simd/function/scalar/atanpi.hpp>
#include <boost/simd/function/simd/atanpi.hpp>

#endif
