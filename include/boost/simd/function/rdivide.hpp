//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RDIVIDE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RDIVIDE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes  the truncated saturated division of its parameters.

    This is a convenient alias of @ref divs
**/
  template<typename T> auto rdivide(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes  the truncated saturated division of its parameters.


      Function object tied to simd::rdivide

      @see simd::rdivide
    **/
    const boost::dispatch::functor<tag::rdivide_> rdivide = {};
  }
} }
#endif

#include <boost/simd/function/definition/rdivide.hpp>
#include <boost/simd/arch/common/scalar/function/divs.hpp>
#include <boost/simd/function/simd/rdivide.hpp>

#endif
