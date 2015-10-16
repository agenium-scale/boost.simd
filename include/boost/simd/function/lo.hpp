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
#ifndef BOOST_SIMD_FUNCTION_LO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LO_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes lo value of its parameter.

  **/
  template<typename T> auto lo(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::lo

      @see simd::lo
    **/
    const boost::dispatch::functor<tag::lo_> lo = {};
  }
} }
#endif

#include <boost/simd/function/definition/lo.hpp>
#include <boost/simd/arch/common/generic/function/lo.hpp>
//#include <boost/simd/arch/common/function/simd/lo.hpp>

#endif
