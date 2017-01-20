//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-bitwise
    This function object computes the bitwise and of the two parameters.
    The operands must share the same bit size.
    The result type is the one of the first operand.
    Infix notation can be used with operator '&',
    but this will not work in scalar mode if any
    operand is floating point because of C++ limitations.

    @par Example:

     @snippet bitwise_and.cpp bitwise_and

   @par Possible output:

     @snippet bitwise_and.txt bitwise_and

  **/
  T0 bitwise_and(T0 const& x, T1 const& y);
} }
#endif

#include <boost/simd/function/scalar/bitwise_and.hpp>
#include <boost/simd/function/simd/bitwise_and.hpp>

#endif
