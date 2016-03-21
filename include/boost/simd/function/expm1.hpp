//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPM1_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPM1_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    exponential function minus one:\f$e^{x}-1\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = expm1(x);
    @endcode

    is similar to:

    @code
    T r = minusone(exp(x));
    @endcode

    @par Notes:

    - result is accurate even for x of small modulus

    @par Decorators

    std_ for floating entries

    @see exp

    @return a value of the same type as the parameter

**/
  template<typename T> auto expm1(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      exponential function minus one:\f$e^{x}-1\f$


      Function object tied to simd::expm1

      @see simd::expm1
    **/
    const boost::dispatch::functor<tag::expm1_> expm1 = {};
  }
} }
#endif

#include <boost/simd/function/scalar/expm1.hpp>
#include <boost/simd/function/simd/expm1.hpp>

#endif
