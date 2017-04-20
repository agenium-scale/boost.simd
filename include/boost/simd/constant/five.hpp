//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FIVE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FIVE_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Five Five (function template)

    Generates the constant five.

    @headerref{<boost/simd/constant/five.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Five();
        @endcode

    2.  @code
        template<typename T> auto Five( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Five constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Five<T>();
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Five( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Five<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/five.hpp>
#include <boost/simd/constant/simd/five.hpp>

#endif
