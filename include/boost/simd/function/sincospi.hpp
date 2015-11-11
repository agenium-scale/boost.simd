//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINCOSPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINCOSPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    Computes simultaneously the sine and cosine
    of the input in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameters of floating type T:

    @code
    T s, c;
    sincospi(x, s, c);
    @endcode

    is similar to:

    @code
    T s =  sinpi(x);
    T c =  cospi(x);
    @endcode


**/
  template<typename T> auto sincospi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      Computes simultaneously the sine and cosine
      of the input in \f$\pi\f$ multiples.


      Function object tied to simd::sincospi

      @see simd::sincospi
    **/
    const boost::dispatch::functor<tag::sincospi_> sincospi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sincospi.hpp>
#include <boost/simd/function/simd/sincospi.hpp>

#endif
