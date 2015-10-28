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
#ifndef BOOST_SIMD_FUNCTION_BITWISE_ORNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_ORNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Computes the bitwise or not of its parameters.

    The operands must share the same bit size.

    The result type is the one of the first operand.

    @par semantic:
    For any given value @c x, of type @c T0 @c y of type @c T1
    of same memory size:

    @code
    T0 r = bitwise_ornot(x, y);
    @endcode

    The code is equivalent to:

    @code
    T0 r = x | ~y;
    @endcode

    @par Alias

    b_ornot

    @see  bitwise_and, bitwise_xor, bitwise_notand,
    bitwise_andnot, bitwise_notor, bitwise_ornot, complement

    @return      a value of the same type as the first input.


**/
  template<typename T0, typename T1> auto bitwise_ornot(T0 const& x, T1 const& y) {}


  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Computes the bitwise or not of its parameters.


      Function object tied to simd::bitwise_ornot

      @see simd::bitwise_ornot
    **/
    const boost::dispatch::functor<tag::bitwise_ornot_> bitwise_ornot = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_ornot.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_ornot.hpp>
//#include <boost/simd/arch/common/function/simd/bitwise_ornot.hpp>

#endif
