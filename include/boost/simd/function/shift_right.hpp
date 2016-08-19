//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-operator
    Function object implementing shift_right capabilities

    return right shift of the first operand by the second
    that must be of integer type and of the same number
    of elements as the first parameter

    Infix notation can be used with operator '>>'

    @par Semantic:

    For every parameters of types respectively T, N:

    @code
    T r = shift_right(x,y);
    @endcode

    is similar to:

    @code
    T r = x >> y;
    @endcode

    @par Alias:
    @c shra, @c shar, @c shrai

    @see  shift_left, shr, rshl, rshr, rol, ror

  **/
  Value shift_right(Value const & v0, IntegerValue const& n);
} }
#endif

#include <boost/simd/function/scalar/shift_right.hpp>
#include <boost/simd/function/simd/shift_right.hpp>

#endif
