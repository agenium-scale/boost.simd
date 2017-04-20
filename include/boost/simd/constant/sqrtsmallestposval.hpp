//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SQRTSMALLESTPOSVAL_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SQRTSMALLESTPOSVAL_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Sqrtsmallestposval Sqrtsmallestposval (function template)

    Generates  Generate the square root of the least non zero positive non denormal
    value of the chosen type.

    @headerref{<boost/simd/constant/sqrtsmallestposval.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Sqrtsmallestposval();
        @endcode

    2.  @code
        template<typename T> auto Sqrtsmallestposval( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Sqrtsmallestposval constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Sqrtsmallestposval<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = 1
    else if T is double
      r =  1.491668146240041e-154;
    else if T is float
      r =   1.0842022e-19;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Sqrtsmallestposval( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Sqrtsmallestposval<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/sqrtsmallestposval.hpp>
#include <boost/simd/constant/simd/sqrtsmallestposval.hpp>

#endif
