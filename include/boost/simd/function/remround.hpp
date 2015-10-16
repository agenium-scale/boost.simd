//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REMROUND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REMROUND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes remround value of its parameter.

  **/
  template<typename T> auto remround(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::remround

      @see simd::remround
    **/
    const boost::dispatch::functor<tag::remround_> remround = {};
  }
} }
#endif

#include <boost/simd/function/definition/remround.hpp>
#include <boost/simd/arch/common/generic/function/remround.hpp>
//#include <boost/simd/arch/common/function/simd/remround.hpp>

#endif
