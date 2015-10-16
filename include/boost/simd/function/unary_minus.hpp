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
#ifndef BOOST_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes unary_minus value of its parameter.

  **/
  template<typename T> auto unary_minus(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::unary_minus

      @see simd::unary_minus
    **/
    const boost::dispatch::functor<tag::unary_minus_> unary_minus = {};
  }
} }
#endif

#include <boost/simd/function/definition/unary_minus.hpp>
#include <boost/simd/arch/common/scalar/function/unary_minus.hpp>
//#include <boost/simd/arch/common/function/simd/unary_minus.hpp>

#endif
