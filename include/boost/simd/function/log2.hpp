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
#ifndef BOOST_SIMD_FUNCTION_LOG2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOG2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes log2 value of its parameter.

  **/
  template<typename T> auto log2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::log2

      @see simd::log2
    **/
    const boost::dispatch::functor<tag::log2_> log2 = {};
  }
} }
#endif

#include <boost/simd/function/definition/log2.hpp>
#include <boost/simd/arch/common/scalar/function/log2.hpp>
#include <boost/simd/function/simd/log2.hpp>

#endif
