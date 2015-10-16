//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FNMS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FNMS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes fnms value of its parameter.

  **/
  template<typename T> auto fnms(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::fnms

      @see simd::fnms
    **/
    const boost::dispatch::functor<tag::fnms_> fnms = {};
  }
} }
#endif

#include <boost/simd/function/definition/fnms.hpp>
#include <boost/simd/arch/common/generic/function/fnms.hpp>
//#include <boost/simd/arch/common/function/simd/fnms.hpp>

#endif
