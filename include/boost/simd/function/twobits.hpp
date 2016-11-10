//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TWOBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWOBITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing twobits capabilities

    Computes the twobits of its parameter.

    @par semantic:
    For any given positive integral value (possibly flint) @c n of type @c T:

    @code
    T r = twobits(n);
    @endcode

    returns the value in the same type 0, 1, 2 or 3 according to the two least significant bits of the input.

    for integral types this is eqivalent to n&Three<T>().

  **/
  Value twobits(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/twobits.hpp>
#include <boost/simd/function/simd/twobits.hpp>

#endif
