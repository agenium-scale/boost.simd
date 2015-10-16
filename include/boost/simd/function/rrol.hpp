//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RROL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RROL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes rrol value of its parameter.

  **/
  template<typename T> auto rrol(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::rrol

      @see simd::rrol
    **/
    const boost::dispatch::functor<tag::rrol_> rrol = {};
  }
} }
#endif

#include <boost/simd/function/definition/rrol.hpp>
#include <boost/simd/arch/common/scalar/function/rrol.hpp>
//#include <boost/simd/arch/common/function/simd/rrol.hpp>

#endif
