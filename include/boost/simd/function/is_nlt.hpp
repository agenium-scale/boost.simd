//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NLT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NLT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    TODO Put description here

    This is a convenient alias of is_not_less
**/
  template<typename T> auto is_nlt(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      TODO Put description here


      Function object tied to simd::is_nlt

      @see simd::is_nlt
    **/
    const boost::dispatch::functor<tag::is_nlt_> is_nlt = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_nlt.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_less.hpp>
#include <boost/simd/function/simd/is_nlt.hpp>

#endif
