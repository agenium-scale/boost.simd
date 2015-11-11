//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COTD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COTD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    cotangent of input in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = cotd(x);
    @endcode

    is similar to:

    @code
    T r = cot(inrad(x));
    @endcode

    As most other trigonometric function cotd can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see cos, sin, tan, cot, cotpi

    @return a value of the same type as the parameter

**/
  template<typename T> auto cotd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      cotangent of input in degree.


      Function object tied to simd::cotd

      @see simd::cotd
    **/
    const boost::dispatch::functor<tag::cotd_> cotd = {};
  }
} }
#endif

#include <boost/simd/function/scalar/cotd.hpp>
#include <boost/simd/function/simd/cotd.hpp>

#endif
