//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVTRUNC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVTRUNC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the truncated division of its parameters.

    This is a convenient alias of @ref divfix
**/
  template<typename T> auto divtrunc(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the truncated division of its parameters.


      Function object tied to divtrunc

      @see simd::divtrunc
    **/
    const boost::dispatch::functor<tag::divtrunc_> divtrunc = {};
  }
} }
#endif

#include <boost/simd/function/scalar/divfix.hpp>
#include <boost/simd/function/simd/divtrunc.hpp>

#endif
