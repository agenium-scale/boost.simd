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
#ifndef BOOST_SIMD_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ABS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes the absolute value of its parameter.

    @par Semantic

    For any value @c x of type @c T,

    @code
    T x = abs(x);
    @endcode

    is equivalent to:

    @code
    T r = x < T(0) ? -x : x;
    @endcode

    @par Note:

    Take care that for signed integers the absolute value of @c Valmin is
    @c Valmin (thus negative!). This is a side effect of the 2-complement
    representation of integers. To avoid this, you can use the abss
    saturated functor or convert the input parameter to a larger type
    before taking the absolute value.

    @see  abss, sqr_abs, sqrs, functional::abs

    @param x value whose absolute value will be returned

    @return The absolute value of the parameter.
  **/
  template<typename T> auto abs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Function object tied to simd::abs

      @see simd::abs
    **/
    const boost::dispatch::functor<tag::abs_> abs = {};
  }
} }
#endif

#include <boost/simd/function/definition/abs.hpp>
#include <boost/simd/arch/common/function/scalar/abs.hpp>
//#include <boost/simd/arch/common/function/simd/abs.hpp>

#endif
