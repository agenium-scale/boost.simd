//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_NBDIGITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_NBDIGITS_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Nbdigits Nbdigits (function template)

    Generates the number of mantissa bits of a floating point number,
    and the total number of bits for integral types.


    @headerref{<boost/simd/constant/nbdigits.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Nbdigits();
        @endcode

    2.  @code
        template<typename T> auto Nbdigits( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Nbdigits constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Nbdigits<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = sizeof(T)*8
    else if T is double
      r =  53;
    else if T is float
      r =  24;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Nbdigits( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Nbdigits<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/nbdigits.hpp>
#include <boost/simd/constant/simd/nbdigits.hpp>

#endif
