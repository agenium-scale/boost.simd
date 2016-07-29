//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_PREV_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PREV_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing prev capabilities

    Returns the greatest representable value  strictly less than the parameter

    @par Semantic:

    @code
    T r = prev(x);
    @endcode

    computes the greatest value strictly less than x in type T

    @see next, nextafter, successor, predecessor

  **/
  Value prev(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/prev.hpp>
#include <boost/simd/function/simd/prev.hpp>

#endif
