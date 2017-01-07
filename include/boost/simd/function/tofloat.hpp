//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TOFLOAT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOFLOAT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    This function object convert its parameter to floating point value.

    @see toint,  touint, cast

    @par Example:

       @snippet tofloat.cpp tofloat

    @par Possible output:

       @snippet tofloat.txt tofloat
  **/
  as_floating_t<Value> tofloat(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/tofloat.hpp>
#include <boost/simd/function/simd/tofloat.hpp>

#endif
