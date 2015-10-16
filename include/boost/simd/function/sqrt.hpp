//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes sqrt value of its parameter.

  **/
  template<typename T> auto sqrt(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::sqrt

      @see simd::sqrt
    **/
    const boost::dispatch::functor<tag::sqrt_> sqrt = {};
  }
} }
#endif

#include <boost/simd/function/definition/sqrt.hpp>
#include <boost/simd/arch/common/scalar/function/sqrt.hpp>
//#include <boost/simd/arch/common/function/simd/sqrt.hpp>

#endif
