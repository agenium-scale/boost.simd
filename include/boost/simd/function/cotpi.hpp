//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COTPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COTPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    cotangent of input in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = cotpi(x);
    @endcode

    is similar to:

    @code
    T r = cot(Pi<T>()*x);
    @endcode

    As most other trigonometric function cotd can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see cos, sin, tan, cot, cotpi

    @return a value of the same type as the parameter

**/
  template<typename T> auto cotpi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      cotangent of input in \f$\pi\f$ multiples.


      Function object tied to simd::cotpi

      @see simd::cotpi
    **/
    const boost::dispatch::functor<tag::cotpi_> cotpi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/cotpi.hpp>
#include <boost/simd/function/simd/cotpi.hpp>

#endif
