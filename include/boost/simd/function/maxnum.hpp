//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAXNUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAXNUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    Computes maxnum value of its parameter.

  **/
  template<typename T> auto maxnum(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::maxnum

      @see simd::maxnum
    **/
    const boost::dispatch::functor<tag::maxnum_> maxnum = {};
  }
} }
#endif

#include <boost/simd/function/definition/maxnum.hpp>
#include <boost/simd/arch/common/scalar/function/maxnum.hpp>
//#include <boost/simd/arch/common/function/simd/maxnum.hpp>

#endif
