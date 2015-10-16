//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MEANOF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MEANOF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes meanof value of its parameter.

  **/
  template<typename T> auto meanof(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::meanof

      @see simd::meanof
    **/
    const boost::dispatch::functor<tag::meanof_> meanof = {};
  }
} }
#endif

#include <boost/simd/function/definition/meanof.hpp>
#include <boost/simd/arch/common/generic/function/meanof.hpp>
//#include <boost/simd/arch/common/function/simd/meanof.hpp>

#endif
