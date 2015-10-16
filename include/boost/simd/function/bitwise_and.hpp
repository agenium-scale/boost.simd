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
#ifndef BOOST_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes bitwise_and value of its parameter.

  **/
  template<typename T> auto bitwise_and(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::bitwise_and

      @see simd::bitwise_and
    **/
    const boost::dispatch::functor<tag::bitwise_and_> bitwise_and = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitwise_and.hpp>
#include <boost/simd/arch/common/scalar/function/bitwise_and.hpp>
//#include <boost/simd/arch/common/function/simd/bitwise_and.hpp>

#endif
