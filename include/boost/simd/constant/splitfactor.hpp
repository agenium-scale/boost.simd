//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SPLITFACTOR_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SPLITFACTOR_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Splitfactor Splitfactor (function template)

    Generates  a constant used to split a floating number in two parts,
    in floating point routines (such [two_add](@ref real-two_add) and
    [two_prod](@ref real-two_prod) to get extra precision.


    @headerref{<boost/simd/constant/splitfactor.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Splitfactor();
        @endcode

    2.  @code
        template<typename T> auto Splitfactor( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Splitfactor constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Splitfactor<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = 0
    else if T is double
      r =  pow(2, 27);
    else if T is float
      r =  pow(2, 13);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Splitfactor( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Splitfactor<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/splitfactor.hpp>
#include <boost/simd/constant/simd/splitfactor.hpp>

#endif
