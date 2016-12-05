//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REFINE_RSQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REFINE_RSQRT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing refine_rsqrt capabilities

    Performs a Newton-Raphson step to improve precision of rsqrt estimate.
    This function can be used in conjunction with raw_(rsqrt)
    to add more precision to the estimate if their default
    precision is not enough.

    @par semantic:
    For any given value @c x, @c est  of floating type T:

    @code
    T r =refine_rsqrt(x, est);
    @endcode

    is similar to

    @code
       T r = fma( fnms(x, sqr(est), One<T>()), est*Half<A0>(), est);
    @endcode

    @see rec

  **/
  Value refine_rsqrt(Value const & v0, Value const& est);
} }
#endif

#include <boost/simd/function/scalar/refine_rsqrt.hpp>
#include <boost/simd/function/simd/refine_rsqrt.hpp>

#endif
