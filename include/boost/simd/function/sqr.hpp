//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SQR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes sqr value of its parameter.

  **/
  template<typename T> auto sqr(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::sqr

      @see simd::sqr
    **/
    const boost::dispatch::functor<tag::sqr_> sqr = {};
  }
} }
#endif

#include <boost/simd/function/definition/sqr.hpp>
#include <boost/simd/arch/common/generic/function/sqr.hpp>
//#include <boost/simd/arch/common/function/simd/sqr.hpp>

#endif
