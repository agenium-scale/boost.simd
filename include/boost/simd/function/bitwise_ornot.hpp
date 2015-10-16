//==================================================================================================
/*!
  @file

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

    Computes bitwise_ornot value of its parameter.

  **/
  template<typename T> auto bitwise_ornot(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

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
