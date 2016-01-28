//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FAST_RSQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_RSQRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes fast_rsqrt value of its parameter.

  **/
  template<typename T> auto fast_rsqrt(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::fast_rsqrt

      @see simd::fast_rsqrt
    **/
    const boost::dispatch::functor<tag::fast_rsqrt_> fast_rsqrt = {};
  }
} }
#endif

#include <boost/simd/function/scalar/fast_rsqrt.hpp>

#endif
