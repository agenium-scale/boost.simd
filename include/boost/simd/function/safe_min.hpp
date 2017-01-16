//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

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
    This function object returns a safe mininimal value relative to the input, i.e. a
    value which will not underflow when divided by the input.

   @par Note

      For every parameter of type @c T `safe_min(x)` is similar to: `Sqrtsmallestposval<T>()*abs(x)`


   @par Example:

     @snippet safe_min.cpp safe_min

   @par Possible output:

     @snippet safe_min.txt safe_min

  **/
  Value safe_min(Value const & x);
} }
#endif

#include <boost/simd/function/scalar/safe_min.hpp>
#include <boost/simd/function/simd/safe_min.hpp>

#endif
