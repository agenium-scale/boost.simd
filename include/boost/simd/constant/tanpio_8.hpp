//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TANPIO_8_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TANPIO_8_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Tanpio_8 Tanpio_8 (function template)

    Generates \f$\tan3\frac\pi{8} = \sqrt2 - 1\f$

    @headerref{<boost/simd/constant/tanpio_8.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Tanpio_8();
        @endcode

    2.  @code
        template<typename T> auto Tanpio_8( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Tanpio_8 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Tanpio_8<T>();
    @endcode
    is similar to:
    @code
    T r = sqrt(2.0)-1.0;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Tanpio_8( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Tanpio_8<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/tanpio_8.hpp>
#include <boost/simd/constant/simd/tanpio_8.hpp>

#endif
