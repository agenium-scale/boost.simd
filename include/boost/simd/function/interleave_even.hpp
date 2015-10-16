//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes interleave_even value of its parameter.

  **/
  template<typename T> auto interleave_even(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::interleave_even

      @see simd::interleave_even
    **/
    const boost::dispatch::functor<tag::interleave_even_> interleave_even = {};
  }
} }
#endif

#include <boost/simd/function/definition/interleave_even.hpp>
#include <boost/simd/arch/common/scalar/function/interleave_even.hpp>
//#include <boost/simd/arch/common/function/simd/interleave_even.hpp>

#endif
