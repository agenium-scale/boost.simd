//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVFIX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVFIX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes divfix value of its parameter.

  **/
  template<typename T> auto divfix(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::divfix

      @see simd::divfix
    **/
    const boost::dispatch::functor<tag::divfix_> divfix = {};
  }
} }
#endif

#include <boost/simd/function/definition/divfix.hpp>
#include <boost/simd/arch/common/scalar/function/divfix.hpp>
//#include <boost/simd/arch/common/function/simd/divfix.hpp>

#endif
