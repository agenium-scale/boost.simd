//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_NBEXPONENTBITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_NBEXPONENTBITS_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Nbexponentbits Nbexponentbits (function template)

    Generates the number of exponent bits of a floating point number,

    @headerref{<boost/simd/constant/nbexponentbits.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Nbexponentbits();
        @endcode

    2.  @code
        template<typename T> auto Nbexponentbits( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Nbexponentbits constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Nbexponentbits<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = 0
    else if T is double
      r =  11;
    else if T is float
      r =  8;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Nbexponentbits( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Nbexponentbits<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/nbexponentbits.hpp>
#include <boost/simd/constant/simd/nbexponentbits.hpp>

#endif
