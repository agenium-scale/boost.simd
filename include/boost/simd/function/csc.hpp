//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CSC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CSC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    cosecante of the input in radian.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = csc(x);
    @endcode

    is similar to:

    @code
    T r = rec(sin(x));
    @endcode

    As most other trigonometric function csc can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see cscd, cscpi,

    @return a value of the same type as the parameter

**/
  template<typename T> auto csc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      cosecante of the input in radian.


      Function object tied to simd::csc

      @see simd::csc
    **/
    const boost::dispatch::functor<tag::csc_> csc = {};
  }
} }
#endif

#include <boost/simd/function/scalar/csc.hpp>
#include <boost/simd/function/simd/csc.hpp>

#endif
