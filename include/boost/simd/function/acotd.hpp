//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOTD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOTD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse cotangent in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acotd(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[0, 180[\f$ such that <tt>cotd(r) == x</tt>.

    @see acot

    @return a value of the same type as the parameter

**/
  template<typename T> auto acotd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse cotangent in degree.


      Function object tied to simd::acotd

      @see simd::acotd
    **/
    const boost::dispatch::functor<tag::acotd_> acotd = {};
  }
} }
#endif

#include <boost/simd/function/scalar/acotd.hpp>
#include <boost/simd/function/simd/acotd.hpp>

#endif
