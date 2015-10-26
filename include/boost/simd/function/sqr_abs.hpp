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
#ifndef BOOST_SIMD_FUNCTION_SQR_ABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQR_ABS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the square of the absolute value of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = sqr_abs(x);
    @endcode

    is equivalent to:

    @code
    T r = sqr(abs(x));
    @endcode

    @par Alias

    @c sqr_modulus


    @return      a value of the same type as the input.


**/
  template<typename T> auto sqr_abs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::sqr_abs

      @see simd::sqr_abs
    **/
    const boost::dispatch::functor<tag::sqr_abs_> sqr_abs = {};
  }
} }
#endif

#include <boost/simd/function/definition/sqr_abs.hpp>
#include <boost/simd/arch/common/generic/function/sqr_abs.hpp>
//#include <boost/simd/arch/common/function/simd/sqr_abs.hpp>

#endif
