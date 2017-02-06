//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_ORNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_ORNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-boolean
    This function object returns the logical or of the first
    argument and of the negation the second argument.

    The operands must share the same @ref cardinal_of value.

    The result type is logical type associated to the first argument.


    @par Header <boost/simd/function/logical_ornot.hpp>

   @par Note

     `logical_ornot(x,y)` is similar to: `as_logical_t<T2> r = x || !y`


   @par Example:

     @snippet logical_ornot.cpp logical_ornot

   @par Possible output:

     @snippet logical_ornot.txt logical_ornot

  **/
  as_logical_t<Value0> logical_ornot(Value0 const& x, Value1 const& y);
} }
#endif

#include <boost/simd/function/scalar/logical_ornot.hpp>
#include <boost/simd/function/simd/logical_ornot.hpp>

#endif
