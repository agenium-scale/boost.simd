//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINCOS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINCOS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    Computes the sine and cosine of the input

    For every parameters of floating type T:

    @par Semantic:

    @code
    T s, c;
    sincos(x, s, c);
    @endcode

    is similar to:

    @code
    T s =  sin(x);
    T c =  cos(x);
    @endcode



**/
  template<typename T> auto sincos(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      Computes the sine and cosine of the input


      Function object tied to simd::sincos

      @see simd::sincos
    **/
    const boost::dispatch::functor<tag::sincos_> sincos = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sincos.hpp>
#include <boost/simd/function/simd/sincos.hpp>

#endif
