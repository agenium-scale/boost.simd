//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FMS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FMS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    This function object computes the (fused) multiply substract of these three parameters.

    @par Notes
    The call `fms(a, b, c)` is similar to `a*b-c

    But really conformant fused multiply/add also implies

    - only one rounding

    - no "intermediate" overflow

    fms provides this for all integral types and also each time it is reasonable
    in terms of performance for floating ones (i.e. if the system has the hard
    wired capability).

    If you need pedantic fms capabilities in all circumstances in your own
    code you can use the pedantic_ decorator (can be very expensive).

     @par Decorators

    - pedantic_ ensures the fms properties and allows SIMD acceleration if available.

    @see fma, fnma, fnms

    @par Example:

       @snippet fms.cpp fms

    @par Possible output:

       @snippet fms.txt fms

  **/
  Value fms(Value const& a, Value const& b, Value const& c);
} }
#endif

#include <boost/simd/function/scalar/fms.hpp>
#include <boost/simd/function/simd/fms.hpp>

#endif
