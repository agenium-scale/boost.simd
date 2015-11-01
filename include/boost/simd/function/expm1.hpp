//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPM1_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPM1_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes expm1 value of its parameter.

  **/
  template<typename T> auto expm1(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::expm1

      @see simd::expm1
    **/
    const boost::dispatch::functor<tag::expm1_> expm1 = {};
  }
} }
#endif

#include <boost/simd/function/definition/expm1.hpp>
#include <boost/simd/arch/common/scalar/function/expm1.hpp>
#include <boost/simd/function/simd/expm1.hpp>

#endif
