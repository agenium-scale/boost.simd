//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_THREEEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_THREEEPS_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Threeeps Threeeps (function template)

    Generates a value equal to 3 times [Eps](@ref constant-Eps) of the chosen type

    @headerref{<boost/simd/constant/threeeps.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Threeeps();
        @endcode

    2.  @code
        template<typename T> auto Threeeps( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Threeeps constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Threeeps<T>();
    @endcode
    @code
    if T is integral
      r = 3
    else if T is double
      r =   6.661338147750939e-16;
    else if T is float
      r =  3.5762787e-07;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Threeeps( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Threeeps<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/threeeps.hpp>
#include <boost/simd/constant/simd/threeeps.hpp>

#endif
