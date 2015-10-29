//==================================================================================================
/*!
  @file

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
    T r = abs(x);
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


    Also abs is a very current function name and sometimes a C version can be
    an unwanted concurrent of boost::simd::abs,  you can prefix abs or
    use the alias modulus instead to circumvent this problem.

    @par Alias

    modulus

    @see  abss, sqr_abs, sqrs

    @param x value whose absolute value will be returned

    @return The absolute value of the parameter.
  **/
  template<typename T> auto abs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the absolute value of its parameter.


      Function object tied to simd::abs

      @see simd::abs
    **/
    const boost::dispatch::functor<tag::abs_> abs = {};
  }
} }
#endif

#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/function/simd/abs.hpp>

#endif
