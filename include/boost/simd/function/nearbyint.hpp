//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEARBYINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing nearbyint capabilities

    Computes the rounded to even value of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = nearbyint(x);
    @endcode

    Returns the nearest integer to x.

    @par Note:

    to even means that half integer values are rounded to the nearest
    even value.

    This function is in general speedier than @ref round which to the rouding on
    half integer values away from zero.

    @see round
  **/
  const boost::dispatch::functor<tag::nearbyint_> nearbyint = {};
} }
#endif

#include <boost/simd/function/scalar/nearbyint.hpp>
#include <boost/simd/function/simd/nearbyint.hpp>

#endif
