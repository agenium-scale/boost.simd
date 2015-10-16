//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOTDEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOTDEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-boolean

    Computes ifnotdec value of its parameter.

  **/
  template<typename T> auto ifnotdec(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::ifnotdec

      @see simd::ifnotdec
    **/
    const boost::dispatch::functor<tag::ifnotdec_> ifnotdec = {};
  }
} }
#endif

#include <boost/simd/function/definition/ifnotdec.hpp>
#include <boost/simd/arch/common/scalar/function/ifnotdec.hpp>
//#include <boost/simd/arch/common/function/simd/ifnotdec.hpp>

#endif
