//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINNUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINNUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    Computes minnum value of its parameter.

  **/
  template<typename T> auto minnum(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::minnum

      @see simd::minnum
    **/
    const boost::dispatch::functor<tag::minnum_> minnum = {};
  }
} }
#endif

#include <boost/simd/function/definition/minnum.hpp>
#include <boost/simd/arch/common/scalar/function/minnum.hpp>
//#include <boost/simd/arch/common/function/simd/minnum.hpp>

#endif
