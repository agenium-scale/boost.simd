//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COSH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COSH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    Returns the hyperbolic cosine: \f$\frac{e^{x}+e^{-x}}2\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = cosh(x);
    @endcode

    is similar to:

    @code
    T r = Half<T>()*(exp(x)+exp(-x));
    @endcode

    @see exp, sinh, Half

    @return a value of the same type as the parameter

**/
  template<typename T> auto cosh(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Returns the hyperbolic cosine: \f$\frac{e^{x}+e^{-x}}2\f$.


      Function object tied to simd::cosh

      @see simd::cosh
    **/
    const boost::dispatch::functor<tag::cosh_> cosh = {};
  }
} }
#endif

#include <boost/simd/function/scalar/cosh.hpp>
#include <boost/simd/function/simd/cosh.hpp>

#endif
