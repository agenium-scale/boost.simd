//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITGET_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITGET_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-bitwise
    This function object returns the value of the ith bit in x as an unsigned integer

   @par Note

      For any given value @c x of type @c T, @c i of type @c I: `as_integer_t<T> r = bitget(x, i)` r contains is 0 or \f$2^i\f$ according to the fact the of rank @c i of @c x is 0 or 1  @see  bitset


   @par Example:

     @snippet bitget.cpp bitget

   @par Possible output:

     @snippet bitget.txt bitget

  **/
  as_integer_t<T> bitget(Value const & x, integer_type i);
} }
#endif

#include <boost/simd/function/scalar/bitget.hpp>
#include <boost/simd/function/simd/bitget.hpp>

#endif
