//==================================================================================================
/*!
  @file
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ERF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ERF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-euler

   Computes the error function:
   \f$\displaystyle \frac{2}{\sqrt\pi}\int_0^{x} e^{-t^2}\mbox{d}t\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = erf(x);
    @endcode


    erf(x, std_) use the call to std::erf from stdlibc++

    @see erfc,  erfcx

    @return a value of the same type as the parameter

  **/
  template<typename T> auto erf(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-euler

      Computes the error function:
      \f$\displaystyle \frac{2}{\sqrt\pi}\int_0^{x} e^{-t^2}\mbox{d}t\f$

      Function object tied to simd::erf

      @see simd::erf
    **/
    const boost::dispatch::functor<tag::erf_> erf = {};
  }
} }
#endif

#include <boost/simd/function/scalar/erf.hpp>
#include <boost/simd/function/simd/erf.hpp>

#endif
