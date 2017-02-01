//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_ORNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_ORNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-bitwise
    This function object computes the bitwise or not of its parameters.
    The operands must share the same bit size.
    The result type is the one of the first operand.


    @par Header <boost/simd/function/bitwise_ornot.hpp>

   @par Example:

     @snippet bitwise_ornot.cpp bitwise_ornot

   @par Possible output:

     @snippet bitwise_ornot.txt bitwise_ornot

  **/
  T0 bitwise_ornot(T0 const &x, T1 const& y);
} }
#endif

#include <boost/simd/function/scalar/bitwise_ornot.hpp>
#include <boost/simd/function/simd/bitwise_ornot.hpp>

#endif
