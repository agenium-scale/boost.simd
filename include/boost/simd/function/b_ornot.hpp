//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_B_ORNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_B_ORNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Computes the bitwise or not of its parameters.

    The operands must share the same bit size.

    The result type is the one of the first operand.

    This is a convenient alias of @ref bitwise_ornot
**/
  template<typename T0, typename T1> auto b_ornot(T0 const& x, T1 const& y) {}


  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Computes the bitwise or not of its parameters.


      Function object tied to simd::b_ornot

      @see simd::b_ornot
    **/
    const boost::dispatch::functor<tag::b_ornot_> b_ornot = {};
  }
} }
#endif

#include <boost/simd/function/scalar/bitwise_ornot.hpp>
#include <boost/simd/function/simd/b_ornot.hpp>

#endif
