//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-bitwise
    This function object returns the bitwise selection of bits from the second
    or third operand according to the setting of the bits
    of the first operand
    The operands must share the same bit size and number of elements.


    @par Header <boost/simd/function/bitwise_select.hpp>

    @par Example:

     @snippet bitwise_select.cpp bitwise_select

   @par Possible output:

     @snippet bitwise_select.txt bitwise_select

  **/
  T0 bitwise_select(SEL const& sel, T0 const &x, T1 const& y);
} }
#endif

#include <boost/simd/function/scalar/bitwise_select.hpp>
#include <boost/simd/function/simd/bitwise_select.hpp>

#endif
