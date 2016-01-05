//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASECD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASECD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

     inverse secant in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asecd(x);
    @endcode

    is similar to:

    @code
    T r =  acosd(rec(x));;
    @endcode

    @see asec

    @return a value of the same type as the parameter

**/
  template<typename T> auto asecd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


       inverse secant in degree.


      Function object tied to simd::asecd

      @see simd::asecd
    **/
    const boost::dispatch::functor<tag::asecd_> asecd = {};
  }
} }
#endif

#include <boost/simd/function/scalar/asecd.hpp>
#include <boost/simd/function/simd/asecd.hpp>

#endif
