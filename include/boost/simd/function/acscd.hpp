//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSCD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSCD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse cosecant in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acscd(x);
    @endcode

    is similar to:

    @code
    T r =  asind(rec(x));;
    @endcode

    @see acsc

    @return a value of the same type as the parameter

**/
  template<typename T> auto acscd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse cosecant in degree.


      Function object tied to simd::acscd

      @see simd::acscd
    **/
    const boost::dispatch::functor<tag::acscd_> acscd = {};
  }
} }
#endif

#include <boost/simd/function/scalar/acscd.hpp>
#include <boost/simd/function/simd/acscd.hpp>

#endif
