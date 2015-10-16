//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes dec value of its parameter.

  **/
  template<typename T> auto dec(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::dec

      @see simd::dec
    **/
    const boost::dispatch::functor<tag::dec_> dec = {};
  }
} }
#endif

#include <boost/simd/function/definition/dec.hpp>
#include <boost/simd/arch/common/generic/function/dec.hpp>
//#include <boost/simd/arch/common/function/simd/dec.hpp>

#endif
