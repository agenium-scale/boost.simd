//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    cotangent of the input in radian.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = cot(x);
    @endcode

    is similar to:

    @code
    T r = cos(x)/sin(x);
    @endcode

    As most other trigonometric function cot can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see cos, sin, tan, cotd, cotpi

    @return a value of the same type as the parameter

**/
  template<typename T> auto cot(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      cotangent of the input in radian.


      Function object tied to simd::cot

      @see simd::cot
    **/
    const boost::dispatch::functor<tag::cot_> cot = {};
  }
} }
#endif

#include <boost/simd/function/scalar/cot.hpp>
#include <boost/simd/function/simd/cot.hpp>

#endif
