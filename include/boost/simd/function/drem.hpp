//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DREM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DREM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing drem capabilities

    Computes the drem of division.
    The return value is x-n*y, where n is the value x/y,
    rounded to the nearest integer (using @ref round2even).

    This is a convenient alias of @ref remainder
  **/
  const boost::dispatch::functor<tag::drem_> drem = {};
} }
#endif

#include <boost/simd/function/scalar/remainder.hpp>
#include <boost/simd/function/simd/drem.hpp>

#endif
