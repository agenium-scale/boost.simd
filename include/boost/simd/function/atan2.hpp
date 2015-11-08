//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATAN2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATAN2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    atan2 function.

    @par Semantic:

    For every parameters of floating types respectively T, T1:

    @code
    T r = atan2(x, y);
    @endcode

    is similar but not fully equivalent to:

    @code
    T r =  atan(y/x);;
    @endcode

    as it is quadrant aware.

    For any real arguments @c x and @c y not both equal to zero, <tt>atan2(x, y)</tt>
    is the angle in radians between the positive x-axis of a plane and the point
    given by the coordinates  <tt>(y, x)</tt>.

    It is also the angle in \f$[-\pi,\pi[\f$ such that
    \f$x/\sqrt{x^2+y^2}\f$ and \f$y/\sqrt{x^2+y^2}\f$
    are respectively the sine and the cosine.

    @see atan


    @return a value of the same type as the parameters

**/
  template<typename T> auto atan2(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      atan2 function.


      Function object tied to simd::atan2

      @see simd::atan2
    **/
    const boost::dispatch::functor<tag::atan2_> atan2 = {};
  }
} }
#endif

#include <boost/simd/function/scalar/atan2.hpp>
#include <boost/simd/function/simd/atan2.hpp>

#endif
