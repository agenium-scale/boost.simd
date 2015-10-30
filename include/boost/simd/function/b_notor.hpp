//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_B_NOTOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_B_NOTOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Computes the bitwise not or of its parameters.

    The operands must share the same bit size.

    The result type is the one of the first operand.

    This is a convenient alias of @ref bitwise_notor
**/
  template<typename T0, typename T1> auto b_notor(T0 const& x, T1 const& y) {}


  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Computes the bitwise not or of its parameters.


      Function object tied to simd::b_notor

      @see simd::b_notor
    **/
    const boost::dispatch::functor<tag::b_notor_> b_notor = {};
  }
} }
#endif

#include <boost/simd/function/definition/b_notor.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_notor.hpp>
#include <boost/simd/function/simd/b_notor.hpp>

#endif
