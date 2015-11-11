//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    sine of the angle in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = sind(x);
    @endcode

    is similar to:

    @code
    T r = sin(Deginrad<T>()*x);
    @endcode

    @see sincosd, sin, sinpi

    As most other trigonometric function sind can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @return a value of the same type as the parameter

**/
  template<typename T> auto sind(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      sine of the angle in degree.


      Function object tied to simd::sind

      @see simd::sind
    **/
    const boost::dispatch::functor<tag::sind_> sind = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sind.hpp>
#include <boost/simd/function/simd/sind.hpp>

#endif
