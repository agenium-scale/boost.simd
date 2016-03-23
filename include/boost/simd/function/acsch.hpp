//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSCH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSCH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-hyperbolic
    Function object implementing acsch capabilities

    Returns the hyperbolic cosecant argument \f$\mathop{\textrm{asinh}}(1/x)\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acsch(x);
    @endcode

    is similar to:

    @code
    T r = asinh(rec(x));
    @endcode

    @see asinh, sinh, rec

  **/
  const boost::dispatch::functor<tag::acsch_> acsch = {};
} }
#endif

#include <boost/simd/function/scalar/acsch.hpp>
#include <boost/simd/function/simd/acsch.hpp>

#endif
