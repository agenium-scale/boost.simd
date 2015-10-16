//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FMS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FMS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes fms value of its parameter.

  **/
  template<typename T> auto fms(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::fms

      @see simd::fms
    **/
    const boost::dispatch::functor<tag::fms_> fms = {};
  }
} }
#endif

#include <boost/simd/function/definition/fms.hpp>
#include <boost/simd/arch/common/generic/function/fms.hpp>
//#include <boost/simd/arch/common/function/simd/fms.hpp>

#endif
