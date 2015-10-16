//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_XOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_XOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes bitwise_xor value of its parameter.

  **/
  template<typename T> auto bitwise_xor(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::bitwise_xor

      @see simd::bitwise_xor
    **/
    const boost::dispatch::functor<tag::bitwise_xor_> bitwise_xor = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_xor.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_xor.hpp>
//#include <boost/simd/arch/common/function/simd/bitwise_xor.hpp>

#endif
