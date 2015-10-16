//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEXT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEXT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    Computes next value of its parameter.

  **/
  template<typename T> auto next(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::next

      @see simd::next
    **/
    const boost::dispatch::functor<tag::next_> next = {};
  }
} }
#endif

#include <boost/simd/function/definition/next.hpp>
#include <boost/simd/arch/common/scalar/function/next.hpp>
//#include <boost/simd/arch/common/function/simd/next.hpp>

#endif
