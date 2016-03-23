//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOSH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOSH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-hyperbolic
    Function object implementing acosh capabilities

    Returns the hyperbolic cosine argument: \f$\log(x+\sqrt{x^2-1})\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acosh(x);
    @endcode

    is similar to:

    @code
    T r = log(x+sqrt{minusone(sqr(x))});
    @endcode

    @see log, sqrt, cosh, minusone

  **/
  const boost::dispatch::functor<tag::acosh_> acosh = {};
} }
#endif

#include <boost/simd/function/scalar/acosh.hpp>
#include <boost/simd/function/simd/acosh.hpp>

#endif
