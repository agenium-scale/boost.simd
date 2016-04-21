//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing fast_rsqrt capabilities

    Computes fast_rsqrt value of its parameter.

  **/
  const boost::dispatch::functor<tag::fast_rsqrt_> fast_rsqrt = {};
} }
#endif

#include <boost/simd/function/scalar/fast_rsqrt.hpp>

#endif
