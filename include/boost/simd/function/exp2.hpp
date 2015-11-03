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
#ifndef BOOST_SIMD_FUNCTION_EXP2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXP2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    Base two exponential function: \f$2^{x}\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = exp2(x);
    @endcode

    is similar to:

    @code
    T r = pow(T(2), x);
    @endcode

    @par Note:
    provisions are made for obtaining a flint result from a flint input.

    @see exp, exp10, pow, pow2

    @return a value of the same type as the parameter

**/
  template<typename T> auto exp2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      base two exponential function: \f$2^{x}\f$

      Function object tied to simd::exp2

      @see simd::exp2
    **/
    const boost::dispatch::functor<tag::exp2_> exp2 = {};
  }
} }
#endif

#include <boost/simd/function/scalar/exp2.hpp>
#include <boost/simd/function/simd/exp2.hpp>

#endif
