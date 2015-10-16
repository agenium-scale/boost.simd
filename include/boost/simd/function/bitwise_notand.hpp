//==================================================================================================
/*!
  @file

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

    Computes bitwise_notand value of its parameter.

  **/
  template<typename T> auto bitwise_notand(T const& x) {}

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
