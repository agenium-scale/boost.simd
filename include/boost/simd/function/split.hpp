//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLIT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLIT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing split capabilities

    SIMD register type-based split

    @c split splits a SIMD register @c x in two SIMD register of half the
    cardinal of @c x containing the same value than @c x but transtyped to
    their associated scalar type.

  **/
  const boost::dispatch::functor<tag::split_> split = {};
} }
#endif

#include <boost/simd/function/scalar/split.hpp>
#include <boost/simd/function/simd/split.hpp>

#endif
