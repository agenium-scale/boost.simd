//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FAST_REC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_REC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-arithmetic
    Function object implementing fast_rec capabilities

    Computes fast_rec value of its parameter.

  **/
  const boost::dispatch::functor<tag::fast_rec_> fast_rec = {};
} }
#endif

#include <boost/simd/function/scalar/fast_rec.hpp>
#include <boost/simd/function/simd/fast_rec.hpp>

#endif
