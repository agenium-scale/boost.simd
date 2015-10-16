//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SAFE_MAX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SAFE_MAX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    Computes safe_max value of its parameter.

  **/
  template<typename T> auto safe_max(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::safe_max

      @see simd::safe_max
    **/
    const boost::dispatch::functor<tag::safe_max_> safe_max = {};
  }
} }
#endif

#include <boost/simd/function/definition/safe_max.hpp>
#include <boost/simd/arch/common/generic/function/safe_max.hpp>
//#include <boost/simd/arch/common/function/simd/safe_max.hpp>

#endif
