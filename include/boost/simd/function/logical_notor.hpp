//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_NOTOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_NOTOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean
    This function object returns the logical or of the negation of the
    first argument with the second argument

    The operands must share the same @ref cardinal_of value.

    The result type is logical type associated to the first argument.


    @par Header <boost/simd/function/logical_notor.hpp>

   @par Example:

     @snippet logical_notor.cpp logical_notor

   @par Possible output:

     @snippet logical_notor.txt logical_notor

  **/
  as_logical_t<Value0> logical_notor(Value0 const& x, Value1 const& y);
} }
#endif

#include <boost/simd/function/scalar/logical_notor.hpp>
#include <boost/simd/function/simd/logical_notor.hpp>

#endif
