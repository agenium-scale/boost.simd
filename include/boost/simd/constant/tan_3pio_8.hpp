//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TAN_3PIO_8_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TAN_3PIO_8_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Tan_3pio_8 Tan_3pio_8 (function template)

    Generates \f$\tan3\frac\pi{8} = \sqrt2 + 1\f$.

    @headerref{<boost/simd/constant/tan_3pio_8.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Tan_3pio_8();
        @endcode

    2.  @code
        template<typename T> auto Tan_3pio_8( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Tan_3pio_8 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Tan_3pio_8<T>();
    @endcode
    is similar to:
    @code
    T r = 1.0+sqrt(2.0);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Tan_3pio_8( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Tan_3pio_8<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/tan_3pio_8.hpp>
#include <boost/simd/constant/simd/tan_3pio_8.hpp>

#endif
