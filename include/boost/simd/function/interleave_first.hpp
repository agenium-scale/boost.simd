//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_FIRST_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes interleave_first value of its parameter.

  **/
  template<typename T> auto interleave_first(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::interleave_first

      @see simd::interleave_first
    **/
    const boost::dispatch::functor<tag::interleave_first_> interleave_first = {};
  }
} }
#endif

#include <boost/simd/function/definition/interleave_first.hpp>
#include <boost/simd/arch/common/scalar/function/interleave_first.hpp>
//#include <boost/simd/arch/common/function/simd/interleave_first.hpp>

#endif
