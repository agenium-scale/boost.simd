//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITSET_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITSET_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-bitwise
    This function object returns x with the ith bit set

   @par Note

      For any given value @c x of type @c T, i  of type @c I: `T r = bitset(x, i)` @see  bitget


   @par Example:

     @snippet bitset.cpp bitset

   @par Possible output:

     @snippet bitset.txt bitset

  **/
  Value bitset(Value const & x, integer const& i);
} }
#endif

#include <boost/simd/function/scalar/bitset.hpp>
#include <boost/simd/function/simd/bitset.hpp>

#endif
