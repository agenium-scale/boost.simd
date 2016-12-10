//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPOCVT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPOCVT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing expocvt capabilities

    Computes the integer conversion of of the exponent bits
    for a given exponent in a floating type.

    @par semantic:
    For any given value @c x of floating type @c T:

    @code
    as_integer_t<T> r = expocvt(x);
    @endcode

    is equivalent to:

    @code
    as_integer_t<T> r = toint(x+Maxexponent<T>();
    @endcode

  **/
  as_integer_T<Value> expocvt(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/expocvt.hpp>
#include <boost/simd/function/simd/expocvt.hpp>

#endif
