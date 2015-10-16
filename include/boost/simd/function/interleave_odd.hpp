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
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes interleave_odd value of its parameter.

  **/
  template<typename T> auto interleave_odd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::interleave_odd

      @see simd::interleave_odd
    **/
    const boost::dispatch::functor<tag::interleave_odd_> interleave_odd = {};
  }
} }
#endif

#include <boost/simd/function/definition/interleave_odd.hpp>
#include <boost/simd/arch/common/scalar/function/interleave_odd.hpp>
//#include <boost/simd/arch/common/function/simd/interleave_odd.hpp>

#endif
