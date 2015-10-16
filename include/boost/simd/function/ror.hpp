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
#ifndef BOOST_SIMD_FUNCTION_ROR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes ror value of its parameter.

  **/
  template<typename T> auto ror(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::ror

      @see simd::ror
    **/
    const boost::dispatch::functor<tag::ror_> ror = {};
  }
} }
#endif

#include <boost/simd/function/definition/ror.hpp>
#include <boost/simd/arch/common/generic/function/ror.hpp>
//#include <boost/simd/arch/common/function/simd/ror.hpp>

#endif
