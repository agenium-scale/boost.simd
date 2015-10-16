//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ILOG2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ILOG2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes ilog2 value of its parameter.

  **/
  template<typename T> auto ilog2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::ilog2

      @see simd::ilog2
    **/
    const boost::dispatch::functor<tag::ilog2_> ilog2 = {};
  }
} }
#endif

#include <boost/simd/function/definition/ilog2.hpp>
#include <boost/simd/arch/common/scalar/function/ilog2.hpp>
//#include <boost/simd/arch/common/function/simd/ilog2.hpp>

#endif
