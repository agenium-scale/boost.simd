//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    Computes the bitwise and of the two parameters.

    The operands must share the same bit size.

    The result type is the one of the first operand.

    Infix notation can be used with operator '&',
    but this will not work in scalar mode if any
    operand is floating point because of C++ limitations.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T0 r = bitwise_and(x,y);
    @endcode

    is similar to:

    @code
    T0 r = x & y;
    @endcode

    @par Alias:
    @c b_and

    @see  bitwise_or, bitwise_xor, bitwise_notand,
    bitwise_andnot, bitwise_notor, bitwise_ornot, complement



    @return a value of the same type as the first parameter

**/
  template<typename T0, typename T1> auto bitwise_and(T0 const& x, T1 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Computes the bitwise and of the two parameters.


      Function object tied to simd::bitwise_and

      @see simd::bitwise_and
    **/
    const boost::dispatch::functor<tag::bitwise_and_> bitwise_and = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_and.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_and.hpp>
#include <boost/simd/function/simd/bitwise_and.hpp>

#endif
