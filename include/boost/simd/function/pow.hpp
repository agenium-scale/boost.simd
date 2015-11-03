//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POW_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POW_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    Computes \f$x^y\f$

    @par Semantic:

    For every parameters of floating types respectively T, U:

    @code
    T r = pow(x,y);
    @endcode

    is similar to:

    @code
    T r = exp(y*log(x));
    @endcode



    @return a value of the same type as the first parameter

**/
  template<typename T, typename U> auto pow(T const& x, U const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      Computes  \f$x^y\f$


      Function object tied to simd::pow

      @see simd::pow
    **/
    const boost::dispatch::functor<tag::pow_> pow = {};
  }
} }
#endif

#include <boost/simd/function/scalar/pow.hpp>
#include <boost/simd/function/simd/pow.hpp>

#endif
