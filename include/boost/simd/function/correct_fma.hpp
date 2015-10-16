//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CORRECT_FMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CORRECT_FMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes correct_fma value of its parameter.

  **/
  template<typename T> auto correct_fma(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::correct_fma

      @see simd::correct_fma
    **/
    const boost::dispatch::functor<tag::correct_fma_> correct_fma = {};
  }
} }
#endif

#include <boost/simd/function/definition/correct_fma.hpp>
#include <boost/simd/arch/common/scalar/function/correct_fma.hpp>
//#include <boost/simd/arch/common/function/simd/correct_fma.hpp>

#endif
