//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse cosine in radian.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acos(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[0, \pi[\f$ such that <tt>cos(r) == x</tt>.
    If @c x is outside \f$[-1, 1[\f$ the result is Nan.

    @see acosd, acospi

    @return a value of the same type as the parameter

**/
  template<typename T> auto acos(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse cosine in radian.


      Function object tied to simd::acos

      @see simd::acos
    **/
    const boost::dispatch::functor<tag::acos_> acos = {};
  }
} }
#endif

#include <boost/simd/function/scalar/acos.hpp>
#include <boost/simd/function/simd/acos.hpp>

#endif
