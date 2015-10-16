//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes is_equal value of its parameter.

  **/
  template<typename T> auto is_equal(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::is_equal

      @see simd::is_equal
    **/
    const boost::dispatch::functor<tag::is_equal_> is_equal = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_equal.hpp>
#include <boost/simd/arch/common/scalar/function/is_equal.hpp>
//#include <boost/simd/arch/common/function/simd/is_equal.hpp>

#endif
