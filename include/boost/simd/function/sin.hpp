//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    sine of the input in radians.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = sin(x);
    @endcode

    As most other trigonometric function sin can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see sincos, sind, sinpi

    @return a value of the same type as the parameter

**/
  template<typename T> auto sin(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      sine of the input in radians.


      Function object tied to simd::sin

      @see simd::sin
    **/
    const boost::dispatch::functor<tag::sin_> sin = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sin.hpp>
#include <boost/simd/function/simd/sin.hpp>

#endif
