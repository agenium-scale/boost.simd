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
#ifndef BOOST_SIMD_FUNCTION_SIGNGAM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGNGAM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-euler

    sign of gamma function

    @par Semantic:

    For every parameter of floating type T0

    @code
    T0 r = signgam(x);
    @endcode

    is similar to

    @code
    T0 r = sign(gamma(x));
    @endcode


    @see gamma,  gammaln

    @return a value of the same type as the parameter

  **/
  template<typename T> auto signgam(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-euler

      Computes the signgam function:
      \f$\displaystyle \int_0^{\infty} t^{x-1}e^{-t}\mbox{d}t\f$


      Function object tied to simd::signgam

      @see simd::signgam
    **/
    const boost::dispatch::functor<tag::signgam_> signgam = {};
  }
} }
#endif

#include <boost/simd/function/scalar/signgam.hpp>
//#include <boost/simd/function/simd/signgam.hpp>

#endif
