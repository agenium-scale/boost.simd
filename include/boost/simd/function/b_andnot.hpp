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
#ifndef BOOST_SIMD_FUNCTION_B_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_B_ANDNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Computes the bitwise and not of its parameters.

    The operands must share the same bit size.

    The result type is the one of the first operand.

    This is a convenient alias of @ref bitwise_andnot
**/
  template<typename T0, typename T1> auto b_andnot(T0 const& x, T1 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Computes the bitwise and not of its parameters.


      Function object tied to simd::b_andnot

      @see simd::b_andnot
    **/
    const boost::dispatch::functor<tag::b_andnot_> b_andnot = {};
  }
} }
#endif

#include <boost/simd/function/definition/b_andnot.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_andnot.hpp>
#include <boost/simd/function/simd/b_andnot.hpp>

#endif
