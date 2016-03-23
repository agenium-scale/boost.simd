//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SLICE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SLICE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing slice capabilities

    SIMD register type-based slice

    @c slice slices a SIMD register @c v in two SIMD register of half the
    cardinal of @c v containing the same value than @c v.

  **/
  const boost::dispatch::functor<tag::slice_> slice = {};
} }
#endif

#include <boost/simd/function/scalar/slice.hpp>
#include <boost/simd/function/simd/slice.hpp>

#endif
