//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SECH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SECH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    Returns the hyperbolic secant: \f$\frac1{\cosh(x)}\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = sech(x);
    @endcode

    is similar to:

    @code
    T r = rec(cosh(x));
    @endcode

    @see rec, cosh

    @return a value of the same type as the parameter

**/
  template<typename T> auto sech(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Returns the hyperbolic secant: \f$\frac1{\cosh(x)}\f$.


      Function object tied to simd::sech

      @see simd::sech
    **/
    const boost::dispatch::functor<tag::sech_> sech = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sech.hpp>
#include <boost/simd/function/simd/sech.hpp>

#endif
