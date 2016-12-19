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
    Function object implementing inearbyint capabilities

    Computes the integer conversion of the nearbyint of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T> r = inearbyint(x);
    @endcode

    is similar to:

    @code
    as_integer_t<T> r = toint(nearbyint(x));
    @endcode

    @par Decorators:

   - pedantic_ as toint does not care about large value, if you need a full range correctness
     use this decorator that computes  saturated_(toint)(nearbyint(x));

    @see nearbyint
  **/

  as_integer_t<Value> inearbyint(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/inearbyint.hpp>
#include <boost/simd/function/simd/inearbyint.hpp>

#endif
