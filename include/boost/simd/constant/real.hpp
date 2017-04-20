//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_REAL_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_REAL_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Real Real (function template)

    Generates a constant from a static real number representation.

    @headerref{<boost/simd/constant/real.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Real();
        @endcode

    2.  @code
        template<typename T> auto Real( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Real constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Real<T>();
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Real( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Real<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/real.hpp>
#include <boost/simd/constant/simd/real.hpp>

#endif
