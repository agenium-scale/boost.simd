//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FAST_TOINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_TOINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes fast_toint value of its parameter.

  **/
  template<typename T> auto fast_toint(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::fast_toint

      @see simd::fast_toint
    **/
    const boost::dispatch::functor<tag::fast_toint_> fast_toint = {};
  }
} }
#endif

#include <boost/simd/function/definition/fast_toint.hpp>
#include <boost/simd/arch/common/scalar/function/fast_toint.hpp>
//#include <boost/simd/arch/common/function/simd/fast_toint.hpp>

#endif
