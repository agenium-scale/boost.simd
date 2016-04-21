//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing sqrt capabilities

    Computes the square root of its parameter. For integers it is the
    truncation of the real square root.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = sqrt(x);
    @endcode

    If full accuracy is not needed a sometimes faster less accurate version of the function
    can be reached using the fast_ decorator.

    @par Decorators

    std_, fast_ for floating entries

  **/
  const boost::dispatch::functor<tag::sqrt_> sqrt = {};
} }
#endif

#include <boost/simd/function/scalar/sqrt.hpp>
#include <boost/simd/function/simd/sqrt.hpp>

#endif
