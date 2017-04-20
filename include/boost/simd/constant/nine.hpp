//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_NINE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_NINE_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Nine Nine (function template)

    Generates 9

    @headerref{<boost/simd/constant/nine.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Nine();
        @endcode

    2.  @code
        template<typename T> auto Nine( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Nine constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = T(9);
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Nine( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Nine<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/nine.hpp>
#include <boost/simd/constant/simd/nine.hpp>

#endif
