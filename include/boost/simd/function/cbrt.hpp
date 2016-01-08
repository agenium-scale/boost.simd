//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CBRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CBRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    Compute the cubic root: \f$\sqrt[3]{x}\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = cbrt(x);
    @endcode

    is similar to:

    @code
    T r = pow(x, T(1/3.0));
    @endcode

    but not equivalent because pow cannot raise a negative base to a fractional exponent.
    we have for all non Nan floating values cbrt(-x) = -cbrt(x).

    cbrt(x, std_) calls std::cbrt from stdlibc++

    @see pow, sqrt

    @return a value of the same type as the parameter

**/
  template<typename T> auto cbrt(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      Compute the cubic root: \f$\sqrt[3]{x}\f$


      Function object tied to simd::cbrt

      @see simd::cbrt
    **/
    const boost::dispatch::functor<tag::cbrt_> cbrt = {};
  }
} }
#endif

#include <boost/simd/function/scalar/cbrt.hpp>
#include <boost/simd/function/simd/cbrt.hpp>

#endif
