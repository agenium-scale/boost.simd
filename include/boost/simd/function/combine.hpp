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
#ifndef BOOST_SIMD_FUNCTION_COMBINE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMBINE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar


**/
  template<typename T> auto combine(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::combine

      @see simd::combine
    **/
    const boost::dispatch::functor<tag::combine_> combine = {};
  }
} }
#endif

#include <boost/simd/function/definition/combine.hpp>
#include <boost/simd/arch/common/scalar/function/combine.hpp>
//#include <boost/simd/arch/common/function/simd/combine.hpp>

#endif
