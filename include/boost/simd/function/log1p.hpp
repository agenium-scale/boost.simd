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
#ifndef BOOST_SIMD_FUNCTION_LOG1P_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOG1P_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes log1p value of its parameter.

  **/
  template<typename T> auto log1p(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::log1p

      @see simd::log1p
    **/
    const boost::dispatch::functor<tag::log1p_> log1p = {};
  }
} }
#endif

#include <boost/simd/function/definition/log1p.hpp>
#include <boost/simd/arch/common/scalar/function/log1p.hpp>
#include <boost/simd/function/simd/log1p.hpp>

#endif
