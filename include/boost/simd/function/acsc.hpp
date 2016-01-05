//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse cosecant in radian.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acsc(x);
    @endcode

    is similar to:

    @code
    T r = asin(rec(x));
    @endcode

    @see acscd

    @return a value of the same type as the parameter

**/
  template<typename T> auto acsc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse cosecant in radian.


      Function object tied to simd::acsc

      @see simd::acsc
    **/
    const boost::dispatch::functor<tag::acsc_> acsc = {};
  }
} }
#endif

#include <boost/simd/function/scalar/acsc.hpp>
#include <boost/simd/function/simd/acsc.hpp>

#endif
