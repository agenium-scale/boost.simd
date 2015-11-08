//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOSD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOSD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse cosine in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acosd(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[0, 180[\f$ such that <tt>cosd(r) == x</tt>.
    If @c x is outside \f$[-1, 1[\f$ the result is Nan.

    @see acos, acospi

    @return a value of the same type as the parameter

**/
  template<typename T> auto acosd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse cosine in degree.


      Function object tied to simd::acosd

      @see simd::acosd
    **/
    const boost::dispatch::functor<tag::acosd_> acosd = {};
  }
} }
#endif

#include <boost/simd/function/scalar/acosd.hpp>
#include <boost/simd/function/simd/acosd.hpp>

#endif
