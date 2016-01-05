//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    secant.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = sec(x);
    @endcode

    is similar to:

    @code
    T r = rec(cos(x));
    @endcode

    @see cos, secd, secpi, rec

    @return a value of the same type as the parameter

**/
  template<typename T> auto sec(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      secant.


      Function object tied to simd::sec

      @see simd::sec
    **/
    const boost::dispatch::functor<tag::sec_> sec = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sec.hpp>
#include <boost/simd/function/simd/sec.hpp>

#endif
