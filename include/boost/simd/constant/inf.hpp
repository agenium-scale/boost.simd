//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INF_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INF_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Inf Inf (function template)

    Generates the Inf IEEE value (\f$\infty\f$) for floating types and maximum representable value for integer types

    @headerref{<boost/simd/constant/inf.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Inf();
        @endcode

    2.  @code
        template<typename T> auto Inf( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Inf constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Inf<T>();
    @endcode
    return IEEE Inf for floating types otherwise the maximum representable value for this type.

    2.  A value of type @c T so that:
    @code
    T x, r = Inf( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Inf<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/inf.hpp>
#include <boost/simd/constant/simd/inf.hpp>

#endif
