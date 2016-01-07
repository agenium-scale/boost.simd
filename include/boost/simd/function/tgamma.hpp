//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TGAMMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TGAMMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-euler

  **/
  template<typename T> auto tgamma(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-euler

      Function object tied to simd::tgamma

      @see simd::tgamma
    **/
    const boost::dispatch::functor<tag::tgamma_> tgamma = {};
  }
} }
#endif

#include <boost/simd/function/scalar/tgamma.hpp>
#include <boost/simd/function/simd/tgamma.hpp>

#endif
