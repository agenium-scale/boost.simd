//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CLZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CLZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes clz value of its parameter.

  **/
  template<typename T> auto clz(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::clz

      @see simd::clz
    **/
    const boost::dispatch::functor<tag::clz_> clz = {};
  }
} }
#endif

#include <boost/simd/function/definition/clz.hpp>
#include <boost/simd/arch/common/scalar/function/clz.hpp>
//#include <boost/simd/arch/common/function/simd/clz.hpp>

#endif
