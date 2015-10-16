//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_SECOND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes interleave_second value of its parameter.

  **/
  template<typename T> auto interleave_second(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::interleave_second

      @see simd::interleave_second
    **/
    const boost::dispatch::functor<tag::interleave_second_> interleave_second = {};
  }
} }
#endif

#include <boost/simd/function/definition/interleave_second.hpp>
#include <boost/simd/arch/common/scalar/function/interleave_second.hpp>
//#include <boost/simd/arch/common/function/simd/interleave_second.hpp>

#endif
