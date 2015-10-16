//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ADDS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ADDS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes adds value of its parameter.

  **/
  template<typename T> auto adds(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::adds

      @see simd::adds
    **/
    const boost::dispatch::functor<tag::adds_> adds = {};
  }
} }
#endif

#include <boost/simd/function/definition/adds.hpp>
#include <boost/simd/arch/common/scalar/function/adds.hpp>
//#include <boost/simd/arch/common/function/simd/adds.hpp>

#endif
