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
#ifndef BOOST_SIMD_FUNCTION_SPLIT_HIGH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLIT_HIGH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    @brief SIMD register type-based split_high

    @c split_high extract the higher half of a SIMD register and convert it
    to the appropriate SIMD register type of corresponding cardinal.

    @see split_low, split, slice

    @return THe higher half of a0 converted to the appropriate SIMD type

**/
  template<typename T> auto split_high(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::split_high

      @see simd::split_high
    **/
    const boost::dispatch::functor<tag::split_high_> split_high = {};
  }
} }
#endif

#include <boost/simd/function/definition/split_high.hpp>
#include <boost/simd/arch/common/scalar/function/split_high.hpp>
//#include <boost/simd/arch/common/function/simd/split_high.hpp>

#endif
