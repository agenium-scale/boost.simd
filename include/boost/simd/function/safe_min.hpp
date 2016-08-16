//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SAFE_MIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SAFE_MIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing safe_min capabilities

    Returns a safe mininimal value relative to the input, i.e. a
    value which will not underflow when divided by the input.

    @par Semantic:

    @code
    T r = safe_min(x);
    @endcode

    is similar to:

    @code
    T r =  x ? Sqrtsmallestposval<T>()*abs(x);
    @endcode

    @see Sqrtsmallestposval

  **/
  Value safe_min(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/safe_min.hpp>
#include <boost/simd/function/simd/safe_min.hpp>

#endif
