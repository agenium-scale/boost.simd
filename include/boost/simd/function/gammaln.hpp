//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GAMMALN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GAMMALN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-euler

    Natural logarithm of the absolute value of the Gamma function


    @par Semantic:

    For every parameter of floating type T

    @code
    T r = gammaln(x);
    @endcode

    is similar to:

    @code
    T r = log(gamma(abs(x)));
    @endcode

    @par Note

    The accuracy of the function is not uniformly good for negative entries
    The algorithm used is currently an adapted vesion of the cephes one.
    For better accuracy in the negative entry case one can use the extern
    boost_math gammaln functor but at a loss of speed.

    However,  as stated in boost math:

      "While the relative errors near the positive roots of lgamma are very low,
       the  function has an infinite number of irrational roots for negative arguments:
       very close to these negative roots only a low absolute error can be guaranteed."

    @return a value of the same type as the parameter

**/
  template<typename T> auto gammaln(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-euler


      Natural logarithm of the absolute value of the Gamma function


      Function object tied to simd::gammaln

      @see simd::gammaln
    **/
    const boost::dispatch::functor<tag::gammaln_> gammaln = {};
  }
} }
#endif

#include <boost/simd/function/scalar/gammaln.hpp>
#include <boost/simd/function/simd/gammaln.hpp>

#endif
