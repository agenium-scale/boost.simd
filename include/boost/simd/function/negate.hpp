//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    Computes negate value of its parameter.

  **/
  template<typename T> auto negate(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::negate

      @see simd::negate
    **/
    const boost::dispatch::functor<tag::negate_> negate = {};
  }
} }
#endif

#include <boost/simd/function/definition/negate.hpp>
#include <boost/simd/arch/common/scalar/function/negate.hpp>
//#include <boost/simd/arch/common/function/simd/negate.hpp>

#endif
