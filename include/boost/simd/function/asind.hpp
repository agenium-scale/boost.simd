//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASIND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASIND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing asind capabilities

    inverse sine in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asind(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[-90, 90[\f$ such that <tt>sin(r) == x</tt>.
    If @c x is outside \f$[-1, 1[\f$ the result is Nan.

  **/
  const boost::dispatch::functor<tag::asind_> asind = {};
} }
#endif

#include <boost/simd/function/scalar/asind.hpp>
#include <boost/simd/function/simd/asind.hpp>

#endif
