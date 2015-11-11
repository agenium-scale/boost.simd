//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATAND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse tangent in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = atand(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[-90, 90[\f$ such that <tt>tand(r) == x</tt>.

    @see atan2d, atan2, atan, atanpi

    @return a value of the same type as the parameter

**/
  template<typename T> auto atand(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse tangent in degree.


      Function object tied to simd::atand

      @see simd::atand
    **/
    const boost::dispatch::functor<tag::atand_> atand = {};
  }
} }
#endif

#include <boost/simd/function/scalar/atand.hpp>
#include <boost/simd/function/simd/atand.hpp>

#endif
