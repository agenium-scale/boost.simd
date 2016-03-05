//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_OR_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_OR_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-bitwise

    return the bitwise or of the two parameters

    The operands must share the same bit size.

    The result type is the one of the first operand.

    Infix notation can be used with operator '|',
    but this will not work in scalar mode if any
    operand is floating point because of C++ limitations.

    @par semantic:
    For any given value @c x, of type @c T0 @c y of type @c T1
    of same memory size:

    @code
    T0 r = bitwise_or(x, y);
    @endcode

    The code is equivalent to:

    @code
    T1 r = x | y;
    @endcode

    @par Alias

    b_or

    @see  bitwise_and, bitwise_or, bitwise_xor, bitwise_notand,
    bitwise_notor, bitwise_ornot, complement

    @return      a value of the same type as the first input.

  **/
  template<typename T0, typename T1> auto bitwise_or(T0 const& x, T1 const& y) {}


  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      return the bitwise or of the two parameters


      Function object tied to boost::simd::bitwise_or

      @see boost::simd::bitwise_or
    **/
    const boost::dispatch::functor<tag::bitwise_or_> bitwise_or = {};
  }
} }
#endif

#include <boost/simd/function/scalar/bitwise_or.hpp>
#include <boost/simd/function/scalar/bitwise_or.hpp>

#endif
