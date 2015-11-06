//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    @return a value of the same type as the parameter

**/
  template<typename T> auto acsch(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Returns the hyperbolic cosecant argument \f$\mathop{\textrm{asinh}}(1/x)\f$


      Function object tied to simd::acsch

      @see simd::acsch
    **/
    const boost::dispatch::functor<tag::acsch_> acsch = {};
  }
} }
#endif

#include <boost/simd/function/scalar/acsch.hpp>
#include <boost/simd/function/simd/acsch.hpp>

#endif
