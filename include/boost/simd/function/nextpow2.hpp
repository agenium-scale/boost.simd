//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEXTPOW2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEXTPOW2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    Computes nextpow2 value of its parameter.

  **/
  template<typename T> auto nextpow2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::nextpow2

      @see simd::nextpow2
    **/
    const boost::dispatch::functor<tag::nextpow2_> nextpow2 = {};
  }
} }
#endif

#include <boost/simd/function/definition/nextpow2.hpp>
#include <boost/simd/arch/common/scalar/function/nextpow2.hpp>
//#include <boost/simd/arch/common/function/simd/nextpow2.hpp>

#endif
