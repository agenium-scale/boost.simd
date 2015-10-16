//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-boolean

    Computes seldec value of its parameter.

  **/
  template<typename T> auto seldec(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::seldec

      @see simd::seldec
    **/
    const boost::dispatch::functor<tag::seldec_> seldec = {};
  }
} }
#endif

#include <boost/simd/function/definition/seldec.hpp>
#include <boost/simd/arch/common/scalar/function/seldec.hpp>
//#include <boost/simd/arch/common/function/simd/seldec.hpp>

#endif
