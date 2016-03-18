//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SECD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SECD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing secd capabilities

    secant of the angle in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = secd(x);
    @endcode

    is similar to:

    @code
    T r = rec(cosd(x));
    @endcode

    @see cosd, sec, secpi, rec

  **/
  const boost::dispatch::functor<tag::secd_> secd = {};
} }
#endif

#include <boost/simd/function/scalar/secd.hpp>
#include <boost/simd/function/simd/secd.hpp>

#endif
