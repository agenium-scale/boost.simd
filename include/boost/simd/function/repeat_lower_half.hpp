//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REPEAT_LOWER_HALF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REPEAT_LOWER_HALF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes repeat_lower_half value of its parameter.

  **/
  template<typename T> auto repeat_lower_half(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::repeat_lower_half

      @see simd::repeat_lower_half
    **/
    const boost::dispatch::functor<tag::repeat_lower_half_> repeat_lower_half = {};
  }
} }
#endif

#include <boost/simd/function/definition/repeat_lower_half.hpp>
#include <boost/simd/arch/common/scalar/function/repeat_lower_half.hpp>
//#include <boost/simd/arch/common/function/simd/repeat_lower_half.hpp>

#endif
