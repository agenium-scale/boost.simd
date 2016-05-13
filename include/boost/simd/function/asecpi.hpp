//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASECPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASECPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing asecpi capabilities

     inverse secant in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asecpi(x);
    @endcode

    is similar to:

    @code
    T r =  acospi(rec(x));;
    @endcode

    @see asec, asecd

  **/
  const boost::dispatch::functor<tag::asecpi_> asecpi = {};
} }
#endif

#include <boost/simd/function/scalar/asecpi.hpp>
#include <boost/simd/function/simd/asecpi.hpp>

#endif
