//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing split_low capabilities

    SIMD register type-based split_low

    @c split_low extract the lower half of a SIMD register and convert it
    to the appropriate SIMD register type of corresponding cardinal.

    @see split_low, split, slice

  **/
  const boost::dispatch::functor<tag::split_low_> split_low = {};
} }
#endif

#include <boost/simd/function/scalar/split_low.hpp>
#include <boost/simd/function/simd/split_low.hpp>

#endif
