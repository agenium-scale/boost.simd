//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REALSQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REALSQRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing realsqrt capabilities

    Returns sqrt function, but asserts
    if called with non real positive values.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = realsqrt(x);
    @endcode

    is similar to:

    @code
    T r = sqrt(x);
    @endcode

    @see sqrt

  **/
  const boost::dispatch::functor<tag::realsqrt_> realsqrt = {};
} }
#endif

#include <boost/simd/function/scalar/realsqrt.hpp>
#include <boost/simd/function/simd/realsqrt.hpp>

#endif
