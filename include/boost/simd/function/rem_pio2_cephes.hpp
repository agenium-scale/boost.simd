//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REM_PIO2_CEPHES_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REM_PIO2_CEPHES_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing rem_pio2_cephes capabilities

    Computes the remainder modulo \f$\pi/2\f$ with cephes algorithm,
    and the angle quadrant between 0 and 3.
    This is a quick version accurate if the input is in \f$[-20\pi,20\pi]\f$.

    @par Semantic:

    For every parameters of floating type T:

    @code
    T r;
    as_integer<T> n;
    rem_pio2_cephes_(x, n, r);
    @endcode

    is similar to:

    @code
    as_integer<T> n = div(iround2even, x, Pio_2<T>());
    T r =  remainder(x, Pio_2<T>());
    @endcode

    @see rem_pio2, rem_pio2_straight,rem_2pi, rem_pio2_medium,

  **/
  const boost::dispatch::functor<tag::rem_pio2_cephes_> rem_pio2_cephes = {};
} }
#endif

#include <boost/simd/function/scalar/rem_pio2_cephes.hpp>
#include <boost/simd/function/simd/rem_pio2_cephes.hpp>

#endif
