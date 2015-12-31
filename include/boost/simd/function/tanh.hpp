//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TANH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TANH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    Returns the hyperbolic tangent: \f$\frac{\sinh(x)}{\cosh(x)}\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = tanh(x);
    @endcode

    is similar to:

    @code
    T r = sinh(x)/cosh(x);
    @endcode


    @return a value of the same type as the parameter

**/
  template<typename T> auto tanh(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Returns the hyperbolic tangent: \f$\frac{\sinh(x)}{\cosh(x)}\f$.


      Function object tied to simd::tanh

      @see simd::tanh
    **/
    const boost::dispatch::functor<tag::tanh_> tanh = {};
  }
} }
#endif

#include <boost/simd/function/scalar/tanh.hpp>
#include <boost/simd/function/simd/tanh.hpp>

#endif
