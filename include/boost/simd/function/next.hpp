//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEXT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEXT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing next capabilities

    Returns the smallest representable value  strictly greater than the parameter

    @par Semantic:

    @code
    T r = next(x);
    @endcode

    computes the smallest value strictly greater than x in type T

    @see nextafter, prev, successor, predecessor

  **/
  Value next(Value const & x);
} }
#endif

#include <boost/simd/function/scalar/next.hpp>
#include <boost/simd/function/simd/next.hpp>

#endif
