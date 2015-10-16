//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SELADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELADD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-boolean

    Computes seladd value of its parameter.

  **/
  template<typename T> auto seladd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::seladd

      @see simd::seladd
    **/
    const boost::dispatch::functor<tag::seladd_> seladd = {};
  }
} }
#endif

#include <boost/simd/function/definition/seladd.hpp>
#include <boost/simd/arch/common/scalar/function/seladd.hpp>
//#include <boost/simd/arch/common/function/simd/seladd.hpp>

#endif
