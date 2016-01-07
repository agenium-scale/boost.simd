//==================================================================================================
/*!
  @file
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GAMMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GAMMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-euler

   Computes the gamma function:
   \f$\displaystyle \int_0^{\infty} t^{x-1}e^{-t}\mbox{d}t\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = gamma(x);
    @endcode

    @see gammaln

    @return a value of the same type as the parameter

  **/
  template<typename T> auto gamma(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-euler

      Computes the gamma function:
      \f$\displaystyle \int_0^{\infty} t^{x-1}e^{-t}\mbox{d}t\f$


      Function object tied to simd::gamma

      @see simd::gamma
    **/
    const boost::dispatch::functor<tag::gamma_> gamma = {};
  }
} }
#endif

#include <boost/simd/function/scalar/gamma.hpp>
//#include <boost/simd/function/simd/gamma.hpp>

#endif
