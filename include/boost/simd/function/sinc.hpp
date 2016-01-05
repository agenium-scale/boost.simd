//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-hyperbolic

    Computes sinc value of its parameter.

  **/
  template<typename T> auto sinc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic

      Function object tied to simd::sinc

      @see simd::sinc
    **/
    const boost::dispatch::functor<tag::sinc_> sinc = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sinc.hpp>
#include <boost/simd/function/simd/sinc.hpp>

#endif
