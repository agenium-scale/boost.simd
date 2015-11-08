//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATAN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse tangent.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = atan(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[-\pi/2, \pi/2[\f$ such that <tt>tan(r) == x</tt>.
    If @c x is outside \f$[-1, 1[\f$ the result is Nan.

    @see atan2, atand, atanpi, nbd_atan2

    @return a value of the same type as the parameter

**/
  template<typename T> auto atan(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse tangent.


      Function object tied to simd::atan

      @see simd::atan
    **/
    const boost::dispatch::functor<tag::atan_> atan = {};
  }
} }
#endif

#include <boost/simd/function/scalar/atan.hpp>
#include <boost/simd/function/simd/atan.hpp>

#endif
