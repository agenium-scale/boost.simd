//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASINH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASINH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    Returns the hyperbolic sine argument: \f$\log(x+\sqrt{x^2+1})\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asinh(x);
    @endcode

    is similar to:

    @code
    T r =  log(x+sqrt(oneplus(sqr(x))));
    @endcode

    @see log, sqrt, sinh, oneplus

    @return a value of the same type as the parameter

**/
  template<typename T> auto asinh(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Returns the hyperbolic sine argument: \f$\log(x+\sqrt{x^2+1})\f$.


      Function object tied to simd::asinh

      @see simd::asinh
    **/
    const boost::dispatch::functor<tag::asinh_> asinh = {};
  }
} }
#endif

#include <boost/simd/function/scalar/asinh.hpp>
#include <boost/simd/function/simd/asinh.hpp>

#endif
