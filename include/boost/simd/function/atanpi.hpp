//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    inverse tangent in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = atanpi(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[-0.5, 0.5[\f$ such that <tt>tanpi(r) == x</tt>.

    @see atan2, atand, atan, nbd_atan2

    @return a value of the same type as the parameter

**/
  template<typename T> auto atanpi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse tangent in \f$\pi\f$ multiples.


      Function object tied to simd::atanpi

      @see simd::atanpi
    **/
    const boost::dispatch::functor<tag::atanpi_> atanpi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/atanpi.hpp>
#include <boost/simd/function/simd/atanpi.hpp>

#endif
