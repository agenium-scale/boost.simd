//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_NOTAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_NOTAND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Computes the bitwise not and of its parameters.

    The operands must share the same bit size.

    The result type is the one of the first operand.

    @par semantic:
    For any given value @c x, of type @c T1 @c y of type @c T2
    of same memory size:

    @code
    T1 r = bitwise_notand(x, y);
    @endcode

    The code is equivalent to:

    @code
    T1 r = ~x & y;
    @endcode

    @par Alias

    b_notand

    @see  bitwise_or, bitwise_xor, bitwise_and,
    bitwise_andnot, bitwise_notor, bitwise_ornot, complement


    @return      a value of the same type as the first input.


**/
  template<typename T0, typename T1> auto bitwise_notand(T0 const& x, T1 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::bitwise_notand

      @see simd::bitwise_notand
    **/
    const boost::dispatch::functor<tag::bitwise_notand_> bitwise_notand = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_notand.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_notand.hpp>
//#include <boost/simd/arch/common/function/simd/bitwise_notand.hpp>

#endif
