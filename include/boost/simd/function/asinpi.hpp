//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASINPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASINPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse sine in \f$\pi\f$ multiples.
    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asinpi(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[-0.5, 0.5[\f$ such that <tt>cos(r) == x</tt>.
    If @c x is outside \f$[-1, 1[\f$ the result is Nan.


    @return a value of the same type as the parameter

**/
  template<typename T> auto asinpi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse sine in \f$\pi\f$ multiples.
      @par Semantic:


      Function object tied to simd::asinpi

      @see simd::asinpi
    **/
    const boost::dispatch::functor<tag::asinpi_> asinpi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/asinpi.hpp>
#include <boost/simd/function/simd/asinpi.hpp>

#endif
