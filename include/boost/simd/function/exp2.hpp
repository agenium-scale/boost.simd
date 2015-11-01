//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXP2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXP2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes exp2 value of its parameter.

  **/
  template<typename T> auto exp2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::exp2

      @see simd::exp2
    **/
    const boost::dispatch::functor<tag::exp2_> exp2 = {};
  }
} }
#endif

#include <boost/simd/function/definition/exp2.hpp>
#include <boost/simd/arch/common/scalar/function/exp2.hpp>
#include <boost/simd/function/simd/exp2.hpp>

#endif
