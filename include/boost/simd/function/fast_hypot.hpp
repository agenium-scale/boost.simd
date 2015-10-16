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
#ifndef BOOST_SIMD_FUNCTION_FAST_HYPOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_HYPOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes fast_hypot value of its parameter.

  **/
  template<typename T> auto fast_hypot(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::fast_hypot

      @see simd::fast_hypot
    **/
    const boost::dispatch::functor<tag::fast_hypot_> fast_hypot = {};
  }
} }
#endif

#include <boost/simd/function/definition/fast_hypot.hpp>
#include <boost/simd/arch/common/scalar/function/fast_hypot.hpp>
//#include <boost/simd/arch/common/function/simd/fast_hypot.hpp>

#endif
