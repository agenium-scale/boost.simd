//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse secant.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asec(x);
    @endcode

    is similar to:

    @code
    T r =  acos(rec(x));
    @endcode

    @see asecd

    @return a value of the same type as the parameter

**/
  template<typename T> auto asec(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse secant.


      Function object tied to simd::asec

      @see simd::asec
    **/
    const boost::dispatch::functor<tag::asec_> asec = {};
  }
} }
#endif

#include <boost/simd/function/scalar/asec.hpp>
#include <boost/simd/function/simd/asec.hpp>

#endif
