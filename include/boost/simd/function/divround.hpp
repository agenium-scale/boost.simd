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
#ifndef BOOST_SIMD_FUNCTION_DIVROUND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVROUND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes divround value of its parameter.

  **/
  template<typename T> auto divround(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::divround

      @see simd::divround
    **/
    const boost::dispatch::functor<tag::divround_> divround = {};
  }
} }
#endif

#include <boost/simd/function/definition/divround.hpp>
#include <boost/simd/arch/common/scalar/function/divround.hpp>
//#include <boost/simd/arch/common/function/simd/divround.hpp>

#endif
