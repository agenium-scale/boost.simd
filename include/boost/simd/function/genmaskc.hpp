//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GENMASKC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GENMASKC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes genmaskc value of its parameter.

  **/
  template<typename T> auto genmaskc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::genmaskc

      @see simd::genmaskc
    **/
    const boost::dispatch::functor<tag::genmaskc_> genmaskc = {};
  }
} }
#endif

#include <boost/simd/function/definition/genmaskc.hpp>
#include <boost/simd/arch/common/scalar/function/genmaskc.hpp>
//#include <boost/simd/arch/common/function/simd/genmaskc.hpp>

#endif
