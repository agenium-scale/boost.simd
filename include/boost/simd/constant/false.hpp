//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FALSE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FALSE_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-False False (function template)

    Generates a value of the logical type associated to the chosen type equal to @c false

    @headerref{<boost/simd/constant/false.hpp>}

    @par Description

    1.  @code
        template<typename T> auto False();
        @endcode

    2.  @code
        template<typename T> auto False( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the False constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = False<T>();
    @endcode
    is equivalent to:
    @code
    T r = false;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = False( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = False<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/false.hpp>
#include <boost/simd/constant/simd/false.hpp>

#endif
