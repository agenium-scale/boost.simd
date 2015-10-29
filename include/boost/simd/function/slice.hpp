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
#ifndef BOOST_SIMD_FUNCTION_SLICE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SLICE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    SIMD register type-based slice

    @c slice slices a SIMD register @c v in two SIMD register of half the
    cardinal of @c v containing the same value than @c v.


**/
  template<typename T> auto slice(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      SIMD register type-based slice


      Function object tied to simd::slice

      @see simd::slice
    **/
    const boost::dispatch::functor<tag::slice_> slice = {};
  }
} }
#endif

#include <boost/simd/function/definition/slice.hpp>
#include <boost/simd/arch/common/scalar/function/slice.hpp>
#include <boost/simd/function/simd/slice.hpp>

#endif
