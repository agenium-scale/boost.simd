//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOTADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOTADD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-boolean

    Computes ifnotadd value of its parameter.

  **/
  template<typename T> auto ifnotadd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::ifnotadd

      @see simd::ifnotadd
    **/
    const boost::dispatch::functor<tag::ifnotadd_> ifnotadd = {};
  }
} }
#endif

#include <boost/simd/function/definition/ifnotadd.hpp>
#include <boost/simd/arch/common/scalar/function/ifnotadd.hpp>
//#include <boost/simd/arch/common/function/simd/ifnotadd.hpp>

#endif
