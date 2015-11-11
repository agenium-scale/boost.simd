//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TAN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    tangent of the input in radians.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = tan(x);
    @endcode

    is similar to:

    @code
    T r = sin(x)/cos(x);
    @endcode


    As most other trigonometric function tan can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see tand, tanpi

    @return a value of the same type as the parameter

**/
  template<typename T> auto tan(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      tangent of the input in radians.


      Function object tied to simd::tan

      @see simd::tan
    **/
    const boost::dispatch::functor<tag::tan_> tan = {};
  }
} }
#endif

#include <boost/simd/function/scalar/tan.hpp>
#include <boost/simd/function/simd/tan.hpp>

#endif
