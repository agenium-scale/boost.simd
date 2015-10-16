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
#ifndef BOOST_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes deinterleave_second value of its parameter.

  **/
  template<typename T> auto deinterleave_second(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::deinterleave_second

      @see simd::deinterleave_second
    **/
    const boost::dispatch::functor<tag::deinterleave_second_> deinterleave_second = {};
  }
} }
#endif

#include <boost/simd/function/definition/deinterleave_second.hpp>
#include <boost/simd/arch/common/scalar/function/deinterleave_second.hpp>
//#include <boost/simd/arch/common/function/simd/deinterleave_second.hpp>

#endif
