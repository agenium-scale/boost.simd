//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FAST_SQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_SQRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes fast_sqrt value of its parameter.

  **/
  template<typename T> auto fast_sqrt(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes fast_sqrt value of its parameter.


      Function object tied to simd::fast_sqrt

      @see simd::fast_sqrt
    **/
    const boost::dispatch::functor<tag::fast_sqrt_> fast_sqrt = {};
  }
} }
#endif

#include <boost/simd/function/definition/fast_sqrt.hpp>
#include <boost/simd/arch/common/scalar/function/fast_sqrt.hpp>
#include <boost/simd/function/simd/fast_sqrt.hpp>

#endif
