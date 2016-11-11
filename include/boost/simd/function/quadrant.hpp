//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_QUADRANT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_QUADRANT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing quadrant capabilities

    Computes the quadrant of its parameter.

    @par semantic:
    For any given positive integral value (possibly flint) @c n of type @c T:

    @code
    T r = quadrant(n);
    @endcode

    returns the value in the same type 0, 1, 2 or 3 according to the two least significant bits of the input.

    for integral types this is eqivalent to n&Three<T>().

  **/
  Value quadrant(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/quadrant.hpp>
#include <boost/simd/function/simd/quadrant.hpp>

#endif
