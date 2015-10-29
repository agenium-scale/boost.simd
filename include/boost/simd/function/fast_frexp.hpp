//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FAST_FREXP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_FREXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    Computes fast_frexp value of its parameter.

  **/
  template<typename T> auto fast_frexp(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Computes fast_frexp value of its parameter.


      Function object tied to simd::fast_frexp

      @see simd::fast_frexp
    **/
    const boost::dispatch::functor<tag::fast_frexp_> fast_frexp = {};
  }
} }
#endif

#include <boost/simd/function/definition/fast_frexp.hpp>
#include <boost/simd/arch/common/scalar/function/fast_frexp.hpp>
#include <boost/simd/function/simd/fast_frexp.hpp>

#endif
