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
#ifndef BOOST_SIMD_FUNCTION_ROUND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROUND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes round value of its parameter.

  **/
  template<typename T> auto round(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::round

      @see simd::round
    **/
    const boost::dispatch::functor<tag::round_> round = {};
  }
} }
#endif

#include <boost/simd/function/definition/round.hpp>
#include <boost/simd/arch/common/scalar/function/round.hpp>
//#include <boost/simd/arch/common/function/simd/round.hpp>

#endif
