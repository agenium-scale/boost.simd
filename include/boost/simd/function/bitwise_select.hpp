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
#ifndef BOOST_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_SELECT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes bitwise_select value of its parameter.

  **/
  template<typename T> auto bitwise_select(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::bitwise_select

      @see simd::bitwise_select
    **/
    const boost::dispatch::functor<tag::bitwise_select_> bitwise_select = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_select.hpp>
#include <boost/simd/arch/common/generic/function/bitwise_select.hpp>
//#include <boost/simd/arch/common/function/simd/bitwise_select.hpp>

#endif
