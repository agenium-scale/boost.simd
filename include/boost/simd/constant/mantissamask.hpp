//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MANTISSAMASK_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MANTISSAMASK_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mantissamask Mantissamask (function template)

    Generates a mask used to compute the mantissa of a floating point value

    @headerref{<boost/simd/constant/mantissamask.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mantissamask();
        @endcode

    2.  @code
        template<typename T> auto Mantissamask( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mantissamask constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Mantissamask<T>();
    @endcode
    @code
    if T is double
      r =  -2.225073858507200889e-308;
    else if T is float
      r =  -1.1754942106924410755e-38;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Mantissamask( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mantissamask<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mantissamask.hpp>
#include <boost/simd/constant/simd/mantissamask.hpp>

#endif
