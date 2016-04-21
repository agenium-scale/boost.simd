//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REMAINDER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REMAINDER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing remainder capabilities

    Computes the remainder of division.
    The return value is x-n*y, where n is the value x/y,
    rounded to the nearest integer (using round2even).

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = remainder(x, y);
    @endcode

    For floating point values the code is similar to:

    @code
    T r = x-divround2even(x, y)*y;
    @endcode

    @par Note:

    As r can be negative, @c remainder is not defined for unsigned types.

    For floating entries:
       -  if x is +/-inf , Nan is returned
       -  If y is +/-0   , Nan is returned
       -  If either argument is NaN, Nan is returned
       -  If the returned value is 0, it will have the same sign as x.

    If correct values for these limit cases do not matter for you, using the fast_ decorator
    can gain some cycles.

    @see mod, rem, modulo

    @par Alias

    @c drem

    @par Decorators

    fast_ for floating entries

  **/
  const boost::dispatch::functor<tag::remainder_> remainder = {};
} }
#endif

#include <boost/simd/function/scalar/remainder.hpp>
#include <boost/simd/function/simd/remainder.hpp>

#endif
