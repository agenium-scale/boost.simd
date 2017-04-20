//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_HALF_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_HALF_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Half Half (function template)

    Generates value \f$\frac12\f$

    @headerref{<boost/simd/constant/half.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Half();
        @endcode

    2.  @code
        template<typename T> auto Half( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Half constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Half<T>();
    @endcode
    is similar for floating types to:
    @code
    T r = T(1)/T(2);
    @endcode
    (0 for integral types)

    2.  A value of type @c T so that:
    @code
    T x, r = Half( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Half<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/half.hpp>
#include <boost/simd/constant/simd/half.hpp>

#endif
