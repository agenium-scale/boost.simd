//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse cotangent.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acot(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[0, \pi[\f$ such that <tt>cot(r) == x</tt>.

    @see acotd

    @return a value of the same type as the parameter

**/
  template<typename T> auto acot(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse cotangent.


      Function object tied to simd::acot

      @see simd::acot
    **/
    const boost::dispatch::functor<tag::acot_> acot = {};
  }
} }
#endif

#include <boost/simd/function/scalar/acot.hpp>
#include <boost/simd/function/simd/acot.hpp>

#endif
