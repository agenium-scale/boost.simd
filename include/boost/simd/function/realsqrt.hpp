//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REALSQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REALSQRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes realsqrt value of its parameter.

  **/
  template<typename T> auto realsqrt(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::realsqrt

      @see simd::realsqrt
    **/
    const boost::dispatch::functor<tag::realsqrt_> realsqrt = {};
  }
} }
#endif

#include <boost/simd/function/definition/realsqrt.hpp>
#include <boost/simd/arch/common/generic/function/realsqrt.hpp>
#include <boost/simd/function/simd/realsqrt.hpp>

#endif
