//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFIX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFIX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Convert to integer by saturated truncation.

    This is a convenient alias of @ref toints
**/
  template<typename T> auto ifix(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Convert to integer by saturated truncation.


      Function object tied to simd::ifix

      @see simd::ifix
    **/
    const boost::dispatch::functor<tag::ifix_> ifix = {};
  }
} }
#endif

#include <boost/simd/function/definition/ifix.hpp>
#include <boost/simd/arch/common/scalar/function/toints.hpp>
#include <boost/simd/function/simd/ifix.hpp>

#endif
