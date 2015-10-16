//==================================================================================================
/*!
  @file

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
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
    the operands must share the same bit size and
    the result type is the one of the first operand
    Infix notation can be used with operator '|',
    but this will not work in scalar mode if any
    operand is floating point because of C++ limitations.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T0 r = bitwise_or(a0,a1);
    @endcode

    is similar to:

    @code
    T0 r = a0 | a1 ;
    @endcode

    @see  bitwise_and, bitwise_xor, bitwise_notand,
    bitwise_andnot, bitwise_notor, bitwise_ornot, complement
    @param a0 First parameter determining the return type

    @param a1 Second parameter

    @return A value of the same type as the first parameter
  **/
  template<typename T0, typename T1> auto bitwise_or(T0 const& a0, T1 const& a1);

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to boost::simd::bitwise_or

      @see boost::simd::bitwise_or
    **/
    const boost::dispatch::functor<tag::bitwise_or_> bitwise_or = {};
  }
} }
#endif

#include <boost/simd/function/scalar/bitwise_or.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_or.hpp>

#endif
