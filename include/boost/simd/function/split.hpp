//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLIT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLIT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes split value of its parameter.

  **/
  template<typename T> auto split(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::split

      @see simd::split
    **/
    const boost::dispatch::functor<tag::split_> split = {};
  }
} }
#endif

#include <boost/simd/function/definition/split.hpp>
#include <boost/simd/arch/common/scalar/function/split.hpp>
//#include <boost/simd/arch/common/function/simd/split.hpp>

#endif
