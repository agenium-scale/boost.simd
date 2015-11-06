//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COTH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COTH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    Returns the hyperbolic cotangent

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = coth(x);
    @endcode

    is similar to:

    @code
    T r = cosh(x)/sinh(x);
    @endcode

    @see sinh, cosh, sinhcosh

    @return a value of the same type as the parameter

**/
  template<typename T> auto coth(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Returns the hyperbolic cotangent


      Function object tied to simd::coth

      @see simd::coth
    **/
    const boost::dispatch::functor<tag::coth_> coth = {};
  }
} }
#endif

#include <boost/simd/function/scalar/coth.hpp>
#include <boost/simd/function/simd/coth.hpp>

#endif
