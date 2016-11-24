//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ARG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ARG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-arithmetic
    Function object implementing arg capabilities

    Computes the angular orientation of its parameter.

    @par semantic:
    For any given value @c x of floating type @c T:

    @code
    T r = arg(x);
    @endcode

    is equivalent to:

    @code
    T r =  (is_negative(x)) ? Pi<T>() : Zero<T>();
    @endcode

    @par Notes:

    - always returns \f$+0\f$ or \f$\pi\f$ taking into account the bit of sign
       even in the Nan case.

    - With the @c pedantic_ decorator returns \f$+0\f$ or \f$\pi\f$ or @ref Nan
      if and only if the input is @ref Nan according to the input sign,

    - This function implement the restriction to real numbers of the
       complex arg(ument) function.

    - This function is not defined for integral types.

    @see is_negative, Pi, Nan

  **/
  Value arg(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/arg.hpp>
#include <boost/simd/function/simd/arg.hpp>

#endif
