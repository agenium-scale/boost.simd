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
#ifndef BOOST_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes bitwise_andnot value of its parameter.

  **/
  template<typename T> auto bitwise_andnot(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::bitwise_andnot

      @see simd::bitwise_andnot
    **/
    const boost::dispatch::functor<tag::bitwise_andnot_> bitwise_andnot = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_andnot.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_andnot.hpp>
//#include <boost/simd/arch/common/function/simd/bitwise_andnot.hpp>

#endif
