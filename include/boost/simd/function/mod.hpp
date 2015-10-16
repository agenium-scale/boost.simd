//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MOD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MOD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes mod value of its parameter.

  **/
  template<typename T> auto mod(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::mod

      @see simd::mod
    **/
    const boost::dispatch::functor<tag::mod_> mod = {};
  }
} }
#endif

#include <boost/simd/function/definition/mod.hpp>
#include <boost/simd/arch/common/generic/function/mod.hpp>
//#include <boost/simd/arch/common/function/simd/mod.hpp>

#endif
