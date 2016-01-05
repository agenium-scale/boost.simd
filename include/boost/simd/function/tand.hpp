//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TAND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    tangent of the input in degrees.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = tand(x);
    @endcode

    is similar to:

    @code
    T r =  sind(x)/cosd(x);
    @endcode

    As most other trigonometric function tand can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see tan, tanpi

    @return a value of the same type as the parameter

**/
  template<typename T> auto tand(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      tangent of the input in degrees.


      Function object tied to simd::tand

      @see simd::tand
    **/
    const boost::dispatch::functor<tag::tand_> tand = {};
  }
} }
#endif

#include <boost/simd/function/scalar/tand.hpp>
#include <boost/simd/function/simd/tand.hpp>

#endif
