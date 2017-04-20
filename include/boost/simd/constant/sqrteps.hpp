//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SQRTEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SQRTEPS_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Sqrteps Sqrteps (function template)

    Generates the square root of constant [Eps](@ref constant-Eps)

    @headerref{<boost/simd/constant/sqrteps.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Sqrteps();
        @endcode

    2.  @code
        template<typename T> auto Sqrteps( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Sqrteps constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Sqrteps<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = 1
    else if T is double
      r =  Pow(2,-26);
    else if T is float
      r =  pow(2,-11.5f);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Sqrteps( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Sqrteps<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/sqrteps.hpp>
#include <boost/simd/constant/simd/sqrteps.hpp>

#endif
