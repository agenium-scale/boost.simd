//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SQRT_2O_3_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SQRT_2O_3_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Sqrt_2o_3 Sqrt_2o_3 (function template)

    Generates \f$\frac{\sqrt2}3\f$

    @headerref{<boost/simd/constant/sqrt_2o_3.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Sqrt_2o_3();
        @endcode

    2.  @code
        template<typename T> auto Sqrt_2o_3( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Sqrt_2o_3 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Sqrt_2o_3<T>();
    @endcode
    is similar to:
    @code
    T r = T(sqrt(T(2)))/T(3);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Sqrt_2o_3( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Sqrt_2o_3<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/sqrt_2o_3.hpp>
#include <boost/simd/constant/simd/sqrt_2o_3.hpp>

#endif
