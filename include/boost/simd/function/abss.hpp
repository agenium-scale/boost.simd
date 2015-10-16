//==================================================================================================
/*!
  @file

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ABSS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ABSS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-arithmetic

    Computes the saturated absolute value of its parameter.

    @par Semantic

    For any value @c x of type @c T,

    @code
    T r = abss(x);
    @endcode

    is equivalent to:

    @code
    T r = (x == Valmin) ? Valmax : (x < T(0) ? -x : x);
    @endcode

    @par Note:

    For integral types, the function always returns a positive value of the same type as the
    entry. For floating types Nan is the obvious and lone exception to this rule.

    This is generally equivalent to @c abs functor except for signed integer
    types for which \c abss(Valmin) is \c Valmax.

    @par Alias

    modulus

    @see  boost::simd::abs, sqr_abss, sqrs

    @param x value whose absolute value will be returned

    @return The  saturated absolute value of the parameter.
  **/
  template<typename T> auto abss(T const& x);

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to boost::simd::abss

      @see abs
    **/
    const boost::dispatch::functor<tag::abss_> abss = {};
  }
} }
#endif

#include <boost/simd/function/scalar/abss.hpp>
//#include <boost/simd/arch/common/function/simd/abss.hpp>

#endif
