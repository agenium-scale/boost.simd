//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COSD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COSD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    cosine of the input in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = cosd(x);
    @endcode

    is similar to:

    @code
    T r = cos(inrad(x));
    @endcode

    As other cosine functions cosd can be used with two parameters as
    @code
    T r = cos(x,  range_);
    @endcode

    see @ref cos for further details

    @see sincosd, cos, cospi

    @return a value of the same type as the parameter

**/
  template<typename T> auto cosd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      cosine of the input in degree.


      Function object tied to simd::cosd

      @see simd::cosd
    **/
    const boost::dispatch::functor<tag::cosd_> cosd = {};
  }
} }
#endif

#include <boost/simd/function/scalar/cosd.hpp>
#include <boost/simd/function/simd/cosd.hpp>

#endif
