//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CSCH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CSCH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    hyperbolic cosecant: \f$\frac1{\sinh(x)}\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = csch(x);
    @endcode

    is similar to:

    @code
    T r = rec(sinh(x));
    @endcode

    @see rec, sinh

    @return a value of the same type as the parameter

**/
  template<typename T> auto csch(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      hyperbolic cosecant: \f$\frac1{\sinh(x)}\f$.


      Function object tied to simd::csch

      @see simd::csch
    **/
    const boost::dispatch::functor<tag::csch_> csch = {};
  }
} }
#endif

#include <boost/simd/function/scalar/csch.hpp>
#include <boost/simd/function/simd/csch.hpp>

#endif
