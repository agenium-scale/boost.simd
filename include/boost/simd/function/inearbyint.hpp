//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    This function object computes the integer conversion of the @ref nearbyint of its parameter.

    @par Note:
    This operation is properly saturated

    @par Decorators:

   - pedantic_ as toint does not care about large value, if you need a full range correctness
     use this decorator that computes  saturated_(toint)(nearbyint(x));

    @see nearbyint, ifloor, iround, ifix, iceil

    @par Example:

       @snippet inearbyint.cpp inearbyint

    @par Possible output:

       @snippet inearbyint.txt inearbyint

  **/

  as_integer_t<Value> inearbyint(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/inearbyint.hpp>
#include <boost/simd/function/simd/inearbyint.hpp>

#endif
