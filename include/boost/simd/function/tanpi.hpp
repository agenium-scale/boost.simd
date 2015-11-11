//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TANPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TANPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    tangent of angle in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = tanpi(x);
    @endcode

    is similar to:

    @code
    T r =  sinpi(x)/cospi(x);;
    @endcode

    As most other trigonometric function tanpi can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see tan, tand

    @return a value of the same type as the parameter

**/
  template<typename T> auto tanpi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      tangent of angle in \f$\pi\f$ multiples.


      Function object tied to simd::tanpi

      @see simd::tanpi
    **/
    const boost::dispatch::functor<tag::tanpi_> tanpi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/tanpi.hpp>
#include <boost/simd/function/simd/tanpi.hpp>

#endif
