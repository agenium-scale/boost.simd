//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ROUND2EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROUND2EVEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes round2even value of its parameter.

  **/
  template<typename T> auto round2even(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::round2even

      @see simd::round2even
    **/
    const boost::dispatch::functor<tag::round2even_> round2even = {};
  }
} }
#endif

#include <boost/simd/function/definition/round2even.hpp>
#include <boost/simd/arch/common/scalar/function/round2even.hpp>
//#include <boost/simd/arch/common/function/simd/round2even.hpp>

#endif
