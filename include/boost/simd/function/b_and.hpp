//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_B_AND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_B_AND_HPP_INCLUDED

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

    This is a convenient alias of @ref bitwise_and
**/
  template<typename T0, typename T1> auto b_and(T0 const& x, T1 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Computes the bitwise and of the two parameters.


      Function object tied to simd::b_and

      @see simd::b_and
    **/
    const boost::dispatch::functor<tag::b_and_> b_and = {};
  }
} }
#endif

#include <boost/simd/function/definition/b_and.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_and.hpp>
#include <boost/simd/function/simd/b_and.hpp>

#endif
