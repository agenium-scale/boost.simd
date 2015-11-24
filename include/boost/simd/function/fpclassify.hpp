//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FPCLASSIFY_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FPCLASSIFY_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-ieee

    Categorizes floating point value arg into the following categories:
    zero, subnormal, normal, infinite, NAN, or implementation-defined category.

    This function is similar to std::fpclassify,  but the return type
    is the integral signed type associated to the floating input type.

    If you want the standard behaviour which return an int in scalar mode you
    can call fpclassify(x, std_).

    @see is_eqz, is_denormal, is_normal, is_inf, is_nan

  **/
  template<typename T> auto fpclassify(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Function object tied to simd::fpclassify

      @see simd::fpclassify
    **/
    const boost::dispatch::functor<tag::fpclassify_> fpclassify = {};
  }
} }
#endif

#include <boost/simd/function/scalar/fpclassify.hpp>
#include <boost/simd/function/simd/fpclassify.hpp>

#endif
