//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INRAD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INRAD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing inrad capabilities

    convert degree to radian.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = inrad(x);
    @endcode

    is similar to:

    @code
    T r = Deginrad<T>()*x;
    @endcode

    @see  indeg, Radindeg, Radindegr, Deginrad

  **/
  const boost::dispatch::functor<tag::inrad_> inrad = {};
} }
#endif

#include <boost/simd/function/scalar/inrad.hpp>
#include <boost/simd/function/simd/inrad.hpp>

#endif
