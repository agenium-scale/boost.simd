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
#ifndef BOOST_SIMD_FUNCTION_SQRS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQRS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the saturated square of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = sqrs(x);
    @endcode

    is similar to:

    @code
    T r = x*x > Valmax ? Valmax : x*x;
    @endcode

    @par Alias

    @c sqrs, saturated_sqr


    @return      a value of the same type as the input.


**/
  template<typename T> auto sqrs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated square of its parameter.


      Function object tied to simd::sqrs

      @see simd::sqrs
    **/
    const boost::dispatch::functor<tag::sqrs_> sqrs = {};
  }
} }
#endif

#include <boost/simd/function/definition/sqrs.hpp>
#include <boost/simd/arch/common/scalar/function/sqrs.hpp>
#include <boost/simd/function/simd/sqrs.hpp>

#endif
