//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATAN2D_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATAN2D_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    atan2d function : atan2 in degrees.

    @par Semantic:

    For every parameters of floating type T:

    @code
    T r = atan2d(x, y);
    @endcode

    is similar but not fully equivalent to:

    @code
    T r =  atand(y/x);;
    @endcode

    as it is quadrant aware.

    For any real arguments @c x and @c y not both equal to zero, <tt>atan2d(x, y)</tt>
    is the angle in degrees between the positive x-axis of a plane and the point
    given by the coordinates  <tt>(y, x)</tt>.

    It is also the angle in \f$[-180,180[\f$ such that
    \f$x/\sqrt{x^2+y^2}\f$ and \f$y/\sqrt{x^2+y^2}\f$
    are respectively the sine and the cosine.

    @see atand


    @return a value of the same type as the parameters

**/
  template<typename T> auto atan2d(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      atan2d function : atan2 in degrees.


      Function object tied to simd::atan2d

      @see simd::atan2d
    **/
    const boost::dispatch::functor<tag::atan2d_> atan2d = {};
  }
} }
#endif

#include <boost/simd/function/scalar/atan2d.hpp>
#include <boost/simd/function/simd/atan2d.hpp>

#endif
