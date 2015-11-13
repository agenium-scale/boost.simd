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

    For every parameters of floating type T:

    @code
    T r = atan2(y, x);
    @endcode

    is similar but not fully equivalent to:

    @code
    T r =  atan(y/x);;
    @endcode

    as it is quadrant aware.

    For any real arguments @c x and @c y not both equal to zero, <tt>atan2(y, xy)</tt>
    is the angle in radians between the positive x-axis of a plane and the point
    given by the coordinates  <tt>(y,x)</tt>.

    It is also the angle in \f$[-\pi,\pi[\f$ for which
    \f$x/\sqrt{x^2+y^2}\f$ and \f$y/\sqrt{x^2+y^2}\f$
    are respectively the sine and the cosine.

    Following IEEE norms
     -  If y is \f$\pm0\f$ and x is negative or -0,\f$\pm\pi\f$ is returned
     -  If y is \f$\pm0\f$ and x is positive or +0, \f$\pm0\f$ is returned
     -  If y is \f$\pm\infty\f$ and x is finite, \f$\pm\pi/2\f$ is returned
     -  If y is \f$\pm\infty\f$ and x is \f$-\infty\f$,\f$\pm3\pi/4\f$ is returned
     -  If y is \f$\pm\infty\f$ and x is \f$+\infty\f$, \f$\pm\pi/4\f$ is returned
     -  If x is \f$\pm0\f$ and y is negative, \f$-\pi/2\f$ is returned
     -  If x is \f$\pm0\f$ and y is positive, \f$+\pi/2\f$  is returned
     -  If x is \f$-\infty\f$ and y is finite and positive, \f$+\pi\f$ is returned
     -  If x is \f$-\infty\f$ and y is finite and negative, \f$-\pi\f$ is returned
     -  If x is \f$+\infty\f$ and y is finite and positive, +0 is returned
     -  If x is \f$+\infty\f$ and y is finite and negative, -0 is returned
     -  If either x is Nan or y is Nan, Nan is returned

     If you want to gain some cycles a fast_ tag is provided. If you use it pairs (x, y)
     where both are null or both are infinite will produce a Nan result which in fact
     is not more absurd than the IEEE choices and will be conforming in all other cases.

  @see atan, atand, atanpi


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
