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
#ifndef BOOST_SIMD_FUNCTION_SPLIT_LOW_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLIT_LOW_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    SIMD register type-based split_low

    @c split_low extract the lower half of a SIMD register and convert it
    to the appropriate SIMD register type of corresponding cardinal.

    @see split_low, split, slice

    @return THe lower half of x converted to the appropriate SIMD type

**/
  template<typename T> auto split_low(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      SIMD register type-based split_low


      Function object tied to simd::split_low

      @see simd::split_low
    **/
    const boost::dispatch::functor<tag::split_low_> split_low = {};
  }
} }
#endif

#include <boost/simd/function/definition/split_low.hpp>
#include <boost/simd/arch/common/scalar/function/split_low.hpp>
#include <boost/simd/function/simd/split_low.hpp>

#endif
