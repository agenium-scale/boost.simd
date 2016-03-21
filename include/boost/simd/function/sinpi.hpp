//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    @return a value of the same type as the parameter

**/
  template<typename T> auto sinpi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      sine of angle in \f$\pi\f$ multiples.



      sine of angle in \f$\pi\f$ multiples.


      Function object tied to simd::sinpi

      @see simd::sinpi
    **/
    const boost::dispatch::functor<tag::sinpi_> sinpi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sinpi.hpp>
#include <boost/simd/function/simd/sinpi.hpp>

#endif
