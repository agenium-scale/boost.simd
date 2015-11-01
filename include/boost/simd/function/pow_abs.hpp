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
#ifndef BOOST_SIMD_FUNCTION_POW_ABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POW_ABS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes pow_abs value of its parameter.

  **/
  template<typename T> auto pow_abs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::pow_abs

      @see simd::pow_abs
    **/
    const boost::dispatch::functor<tag::pow_abs_> pow_abs = {};
  }
} }
#endif

#include <boost/simd/function/definition/pow_abs.hpp>
#include <boost/simd/arch/common/scalar/function/pow_abs.hpp>
#include <boost/simd/function/simd/pow_abs.hpp>

#endif
