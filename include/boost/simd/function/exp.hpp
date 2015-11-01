//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes exp value of its parameter.

  **/
  template<typename T> auto exp(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::exp

      @see simd::exp
    **/
    const boost::dispatch::functor<tag::exp_> exp = {};
  }
} }
#endif

#include <boost/simd/function/definition/exp.hpp>
#include <boost/simd/arch/common/scalar/function/exp.hpp>
#include <boost/simd/function/simd/exp.hpp>

#endif
