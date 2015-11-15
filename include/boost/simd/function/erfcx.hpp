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
#ifndef BOOST_SIMD_FUNCTION_ERFCX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ERFCX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-euler

   Computes the  underflow-compensating error function erfcx(x) = exp(x^2) erfc(x):
   \f$\displaystyle e^{x^2}\frac{2}{\sqrt\pi}\int_0^{x} e^{-t^2}\mbox{d}t\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = erfcx(x);
    @endcode

    is similar to:

    @code
    T r = exp(sqr(x))*erfc(x);
    @endcode

    But avoid underflow as much as possible.

    @see erfc, erf

    @return a value of the same type as the parameter

  **/
  template<typename T> auto erfcx(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-euler

      Underflow-compensating error function:
      \f$\displaystyle e^{x^2}\frac{2}{\sqrt\pi}\int_0^{x} e^{-t^2}\mbox{d}t\f$

      Function object tied to simd::erfcx

      @see simd::erfcx
    **/
    const boost::dispatch::functor<tag::erfcx_> erfcx = {};
  }
} }
#endif

#include <boost/simd/function/scalar/erfcx.hpp>
#include <boost/simd/function/simd/erfcx.hpp>

#endif
