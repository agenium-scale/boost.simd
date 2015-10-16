//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes shuffle value of its parameter.

  **/
  template<typename T> auto shuffle(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::shuffle

      @see simd::shuffle
    **/
    const boost::dispatch::functor<tag::shuffle_> shuffle = {};
  }
} }
#endif

#include <boost/simd/function/definition/shuffle.hpp>
#include <boost/simd/arch/common/scalar/function/shuffle.hpp>
//#include <boost/simd/arch/common/function/simd/shuffle.hpp>

#endif
