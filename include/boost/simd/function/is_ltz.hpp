//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-predicates

    Computes is_ltz value of its parameter.

  **/
  template<typename T> auto is_ltz(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_ltz

      @see simd::is_ltz
    **/
    const boost::dispatch::functor<tag::is_ltz_> is_ltz = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_ltz.hpp>
#include <boost/simd/arch/common/scalar/function/is_ltz.hpp>
//#include <boost/simd/arch/common/function/simd/is_ltz.hpp>

#endif
