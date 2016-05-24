//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_TRIGONOMETRIC_HPP_INCLUDED
#define BOOST_SIMD_TRIGONOMETRIC_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-trigonometric Trigonometric functions

    Algorithms for computing scalar and SIMD versions of
    trigonometric and inverse trigonometric functions.
  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-trigonometric Trigonometric Callable Objects
    Callable objects version of @ref group-trigonometric

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-trigonometric section.
  **/
} }

#include <boost/simd/function/acosd.hpp>
#include <boost/simd/function/acos.hpp>
#include <boost/simd/function/acospi.hpp>
#include <boost/simd/function/acotd.hpp>
#include <boost/simd/function/acot.hpp>
#include <boost/simd/function/acscd.hpp>
#include <boost/simd/function/acsc.hpp>
#include <boost/simd/function/asecd.hpp>
#include <boost/simd/function/asec.hpp>
#include <boost/simd/function/asind.hpp>
#include <boost/simd/function/asin.hpp>
#include <boost/simd/function/asinpi.hpp>
#include <boost/simd/function/atan2d.hpp>
#include <boost/simd/function/atan2.hpp>
#include <boost/simd/function/atand.hpp>
#include <boost/simd/function/atan.hpp>
#include <boost/simd/function/atanpi.hpp>
#include <boost/simd/function/cosd.hpp>
#include <boost/simd/function/cos.hpp>
#include <boost/simd/function/cospi.hpp>
#include <boost/simd/function/cotd.hpp>
#include <boost/simd/function/cot.hpp>
#include <boost/simd/function/cotpi.hpp>
#include <boost/simd/function/cscd.hpp>
#include <boost/simd/function/csc.hpp>
#include <boost/simd/function/cscpi.hpp>
#include <boost/simd/function/indeg.hpp>
#include <boost/simd/function/inrad.hpp>
#include <boost/simd/function/rem_2pi.hpp>
#include <boost/simd/function/rem_pio2_cephes.hpp>
#include <boost/simd/function/rem_pio2.hpp>
#include <boost/simd/function/rem_pio2_medium.hpp>
#include <boost/simd/function/rem_pio2_straight.hpp>
#include <boost/simd/function/secd.hpp>
#include <boost/simd/function/sec.hpp>
#include <boost/simd/function/secpi.hpp>
#include <boost/simd/function/sinc.hpp>
#include <boost/simd/function/sincosd.hpp>
#include <boost/simd/function/sincos.hpp>
#include <boost/simd/function/sincospi.hpp>
#include <boost/simd/function/sincpi.hpp>
#include <boost/simd/function/sind.hpp>
#include <boost/simd/function/sin.hpp>
#include <boost/simd/function/sinpi.hpp>
#include <boost/simd/function/tand.hpp>
#include <boost/simd/function/tan.hpp>
#include <boost/simd/function/tanpi.hpp>

#endif
