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
#ifndef BOOST_SIMD_FUNCTION_CBRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CBRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes cbrt value of its parameter.

  **/
  template<typename T> auto cbrt(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::cbrt

      @see simd::cbrt
    **/
    const boost::dispatch::functor<tag::cbrt_> cbrt = {};
  }
} }
#endif

#include <boost/simd/function/definition/cbrt.hpp>
#include <boost/simd/arch/common/scalar/function/cbrt.hpp>
#include <boost/simd/function/simd/cbrt.hpp>

#endif
