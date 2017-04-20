//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_HALFEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_HALFEPS_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Halfeps Halfeps (function template)

    Generates the machine epsilon.

    @headerref{<boost/simd/constant/halfeps.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Halfeps();
        @endcode

    2.  @code
        template<typename T> auto Halfeps( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Halfeps constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Halfeps<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = T(1)
    else if T is double
      r =  pow(2, -54);
    else if T is float
      r =  pow(2.0f, -24);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Halfeps( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Halfeps<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/halfeps.hpp>
#include <boost/simd/constant/simd/halfeps.hpp>

#endif
