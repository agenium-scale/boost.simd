//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-reduction

    Computes nbtrue value of its parameter.

  **/
  template<typename T> auto nbtrue(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-reduction

      Function object tied to simd::nbtrue

      @see simd::nbtrue
    **/
    const boost::dispatch::functor<tag::nbtrue_> nbtrue = {};
  }
} }
#endif

#include <boost/simd/function/definition/nbtrue.hpp>
#include <boost/simd/arch/common/scalar/function/nbtrue.hpp>
//#include <boost/simd/arch/common/function/simd/nbtrue.hpp>

#endif
