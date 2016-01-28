//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FAST_TRUNC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_TRUNC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes fast_trunc value of its parameter.

  **/
  template<typename T> auto fast_trunc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::fast_trunc

      @see simd::fast_trunc
    **/
    const boost::dispatch::functor<tag::fast_trunc_> fast_trunc = {};
  }
} }
#endif

#include <boost/simd/function/scalar/fast_trunc.hpp>

#endif
