//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing asinh capabilities

    Returns the hyperbolic sine argument: \f$\log(x+\sqrt{x^2+1})\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asinh(x);
    @endcode

    is similar to:

    @code
    T r =  log(x+sqrt(inc(sqr(x))));
    @endcode

    @see log, sqrt, sinh, inc

  **/
  const boost::dispatch::functor<tag::asinh_> asinh = {};
} }
#endif

#include <boost/simd/function/scalar/asinh.hpp>
#include <boost/simd/function/simd/asinh.hpp>

#endif
