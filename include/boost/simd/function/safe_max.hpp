//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SAFE_MAX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SAFE_MAX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-ieee
    This function object returns a safe maximal value relative to the input,  i.e. a
    value which will not overflow when multiplied by the input.

   @par Note

      For every parameter of type @c T `safe_max(x)` is similar to: `x ? Sqrtvalmax<T>()/abs(x) : Inf<T>()`


   @par Example:

     @snippet safe_max.cpp safe_max

   @par Possible output:

     @snippet safe_max.txt safe_max

  **/
  Value safe_max(Value const & x);
} }
#endif

#include <boost/simd/function/scalar/safe_max.hpp>
#include <boost/simd/function/simd/safe_max.hpp>

#endif
