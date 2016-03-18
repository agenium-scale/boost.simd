//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing divtrunc capabilities

    Computes the truncated division of its parameters.

    This is a convenient alias of @ref divfix
  **/
  const boost::dispatch::functor<tag::divtrunc_> divtrunc = {};
} }
#endif

#include <boost/simd/function/scalar/divfix.hpp>
#include <boost/simd/function/simd/divtrunc.hpp>

#endif
