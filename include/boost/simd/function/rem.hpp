//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing rem capabilities

    Computes the remainder of division.
    The return value is x-n*y, where n is the value x/y,
    rounded toward zero.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = rem(x, y);
    @endcode

    For floating point values the code is similar to:

    @code
    T r = x-divfix(x, y)*y;
    @endcode

    For floating entries:
       -  if x is +/-inf , Nan is returned
       -  if x is +/-0 and y is not 0 x is returned
       -  If y is +/-0, Nan is returned
       -  If either argument is NaN, Nan is returned

       If correct values for these limit cases do not matter for you, using the fast_ decorator
    can gain some cycles.

    The returned value has the same sign as x and is less than y in magnitude.

    @par Decorators

    std_,  fast_ for floating entries

    @par Alias

    @c fmod,  @c remfix

    @see remainder, mod, modulo

  **/
  const boost::dispatch::functor<tag::rem_> rem = {};
} }
#endif

#include <boost/simd/function/scalar/rem.hpp>
#include <boost/simd/function/simd/rem.hpp>

#endif
