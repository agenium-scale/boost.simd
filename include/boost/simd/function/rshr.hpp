//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RSHR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RSHR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes rshr value of its parameter.

  **/
  template<typename T> auto rshr(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::rshr

      @see simd::rshr
    **/
    const boost::dispatch::functor<tag::rshr_> rshr = {};
  }
} }
#endif

#include <boost/simd/function/definition/rshr.hpp>
#include <boost/simd/arch/common/scalar/function/rshr.hpp>
//#include <boost/simd/arch/common/function/simd/rshr.hpp>

#endif
