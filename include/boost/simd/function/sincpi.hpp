//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINCPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINCPI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-hyperbolic

    Computes sincpi value of its parameter.

  **/
  template<typename T> auto sincpi(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic

      Function object tied to simd::sincpi

      @see simd::sincpi
    **/
    const boost::dispatch::functor<tag::sincpi_> sincpi = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sincpi.hpp>
#include <boost/simd/function/simd/sincpi.hpp>

#endif
