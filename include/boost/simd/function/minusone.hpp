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
#ifndef BOOST_SIMD_FUNCTION_MINUSONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINUSONE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes minusone value of its parameter.

  **/
  template<typename T> auto minusone(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::minusone

      @see simd::minusone
    **/
    const boost::dispatch::functor<tag::minusone_> minusone = {};
  }
} }
#endif

#include <boost/simd/function/definition/minusone.hpp>
#include <boost/simd/arch/common/scalar/function/minusone.hpp>
//#include <boost/simd/arch/common/function/simd/minusone.hpp>

#endif
