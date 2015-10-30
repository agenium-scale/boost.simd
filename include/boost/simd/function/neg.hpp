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
#ifndef BOOST_SIMD_FUNCTION_NEG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    return the elementwise unary minus of the parameter

    Infix notation can be used with operator '-'

    This is a convenient alias of @ref unary_minus
**/
  template<typename T> auto neg(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      return the elementwise unary minus of the parameter


      Function object tied to simd::neg

      @see simd::neg
    **/
    const boost::dispatch::functor<tag::neg_> neg = {};
  }
} }
#endif

#include <boost/simd/function/definition/neg.hpp>
#include <boost/simd/arch/common/scalar/function/unary_minus.hpp>
#include <boost/simd/function/simd/neg.hpp>

#endif
