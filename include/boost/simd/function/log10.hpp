//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOG10_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOG10_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes log10 value of its parameter.

  **/
  template<typename T> auto log10(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::log10

      @see simd::log10
    **/
    const boost::dispatch::functor<tag::log10_> log10 = {};
  }
} }
#endif

#include <boost/simd/function/definition/log10.hpp>
#include <boost/simd/arch/common/scalar/function/log10.hpp>
#include <boost/simd/function/simd/log10.hpp>

#endif
