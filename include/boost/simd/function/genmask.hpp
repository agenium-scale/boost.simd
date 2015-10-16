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
#ifndef BOOST_SIMD_FUNCTION_GENMASK_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GENMASK_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes genmask value of its parameter.

  **/
  template<typename T> auto genmask(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::genmask

      @see simd::genmask
    **/
    const boost::dispatch::functor<tag::genmask_> genmask = {};
  }
} }
#endif

#include <boost/simd/function/definition/genmask.hpp>
#include <boost/simd/arch/common/scalar/function/genmask.hpp>
//#include <boost/simd/arch/common/function/simd/genmask.hpp>

#endif
