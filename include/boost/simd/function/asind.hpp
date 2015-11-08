//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASIND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASIND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    inverse sine in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = asind(x);
    @endcode

    Returns the arc @c r in the interval
    \f$[-90, 90[\f$ such that <tt>sin(r) == x</tt>.
    If @c x is outside \f$[-1, 1[\f$ the result is Nan.


    @return a value of the same type as the parameter

**/
  template<typename T> auto asind(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      inverse sine in degree.


      Function object tied to simd::asind

      @see simd::asind
    **/
    const boost::dispatch::functor<tag::asind_> asind = {};
  }
} }
#endif

#include <boost/simd/function/scalar/asind.hpp>
#include <boost/simd/function/simd/asind.hpp>

#endif
