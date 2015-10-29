//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    SIMD register type-based split

    @c split splits a SIMD register @c x in two SIMD register of half the
    cardinal of @c x containing the same value than @c x but transtyped to
    their associated scalar type.


**/
  template<typename T> auto split(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::split

      @see simd::split
    **/
    const boost::dispatch::functor<tag::split_> split = {};
  }
} }
#endif

#include <boost/simd/function/definition/split.hpp>
#include <boost/simd/arch/common/scalar/function/split.hpp>
#include <boost/simd/function/simd/split.hpp>

#endif
