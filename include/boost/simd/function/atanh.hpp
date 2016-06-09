//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATANH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATANH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-hyperbolic
    Function object implementing atanh capabilities

    Returns the hyperbolic tangent argument \f$\frac12\log\frac{x^2-1}{x^2+1}\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = atanh(x);
    @endcode

    is similar to:

    @code
    T r = Half<T>()*log(dec(sqr(x))/inc(sqr(x)));
    @endcode

    @see log, Half, dec, inc

  **/
  const boost::dispatch::functor<tag::atanh_> atanh = {};
} }
#endif

#include <boost/simd/function/scalar/atanh.hpp>
#include <boost/simd/function/simd/atanh.hpp>

#endif
