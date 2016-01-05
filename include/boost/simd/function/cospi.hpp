//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COSPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COSPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    cosine of angle in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameter of floating or integral type T

    @code
    T r = cospi(x);
    @endcode

    is similar to:

    @code
    T r = cos(Pi<T>()*x);
    @endcode

    @par Note

    As other cosine functions cospi can be used with two parameters as
    @code
    T r = cos(x, range_);
    @endcode

    see @ref cos for further details

    As it conveys a peculiar meaning,  unlike the orher cosine, cospi is defined
    for integral types and the result of cospi(n) coincides with \f$(-1)^n\f$.

    Take care that large floating entries are always integral and even !

    @see sincospi, cos, cosd

    @return a value of the same type as the parameter

**/
  template<typename T> auto cospi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      cosine of angle in \f$\pi\f$ multiples.


      Function object tied to simd::cospi

      @see simd::cospi
    **/
    const boost::dispatch::functor<tag::cospi_> cospi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/cospi.hpp>
#include <boost/simd/function/simd/cospi.hpp>

#endif
