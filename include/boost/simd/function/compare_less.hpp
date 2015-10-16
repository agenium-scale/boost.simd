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
#ifndef BOOST_SIMD_FUNCTION_COMPARE_LESS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_LESS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-reduction

    Computes compare_less value of its parameter.

  **/
  template<typename T> auto compare_less(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-reduction

      Function object tied to simd::compare_less

      @see simd::compare_less
    **/
    const boost::dispatch::functor<tag::compare_less_> compare_less = {};
  }
} }
#endif

#include <boost/simd/function/definition/compare_less.hpp>
#include <boost/simd/arch/common/scalar/function/compare_less.hpp>
//#include <boost/simd/arch/common/function/simd/compare_less.hpp>

#endif
