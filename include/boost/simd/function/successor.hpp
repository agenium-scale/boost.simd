//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SUCCESSOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SUCCESSOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing successor capabilities

    Returns the n-th least element strictly greater than the parameter

    @par Semantic:

    @code
    T r = successor(x,n);
    @endcode

    computes the @c n-th least representable value strictly greater than x in its type.
    n must be positive or null.

    For integer it saturate at @ref Valmax, for floating point numbers, all @ref Inf
    strict successors are @ref Nan.

  **/
  Value successor(Value const& x, IntegerValue const& n);
} }
#endif

#include <boost/simd/function/scalar/successor.hpp>
#include <boost/simd/function/simd/successor.hpp>

#endif
