//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POW2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POW2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes pow2 value of its parameter.

  **/
  template<typename T> auto pow2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::pow2

      @see simd::pow2
    **/
    const boost::dispatch::functor<tag::pow2_> pow2 = {};
  }
} }
#endif

#include <boost/simd/function/definition/pow2.hpp>
#include <boost/simd/arch/common/scalar/function/pow2.hpp>
#include <boost/simd/function/simd/pow2.hpp>

#endif
