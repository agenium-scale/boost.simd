//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SECPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SECPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    secant of the angle in pi multiples.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = secpi(x);
    @endcode

    is similar to:

    @code
    T r = rec(cospi(x));
    @endcode

    @see secd, sec, cospi, cos

    @return a value of the same type as the parameter

**/
  template<typename T> auto secpi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      secant of the angle in pi multiples.


      Function object tied to simd::secpi

      @see simd::secpi
    **/
    const boost::dispatch::functor<tag::secpi_> secpi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/secpi.hpp>
#include <boost/simd/function/simd/secpi.hpp>

#endif
