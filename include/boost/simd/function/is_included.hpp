//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_INCLUDED_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_INCLUDED_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-reduction

    Computes is_included value of its parameter.

  **/
  template<typename T> auto is_included(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-reduction

      Function object tied to simd::is_included

      @see simd::is_included
    **/
    const boost::dispatch::functor<tag::is_included_> is_included = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_included.hpp>
#include <boost/simd/arch/common/scalar/function/is_included.hpp>
//#include <boost/simd/arch/common/function/simd/is_included.hpp>

#endif
