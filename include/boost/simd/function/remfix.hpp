//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REMFIX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REMFIX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing remfix capabilities

    Computes the remainder of division.
    The return value is x-n*y, where n is the value x/y,
    rounded toward zero.

    This is a convenient alias of @ref rem
  **/
  const boost::dispatch::functor<tag::remfix_> remfix = {};
} }
#endif

#include <boost/simd/function/scalar/rem.hpp>
#include <boost/simd/function/simd/remfix.hpp>

#endif
