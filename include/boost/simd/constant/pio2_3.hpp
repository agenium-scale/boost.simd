//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_PIO2_3_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_PIO2_3_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Pio2_3 Pio2_3 (function template)

    Generates a constant used in modular computation involving \f$\pi\f$

    @headerref{<boost/simd/constant/pio2_3.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Pio2_3();
        @endcode

    2.  @code
        template<typename T> auto Pio2_3( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Pio2_3 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Pio2_3<T>();
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Pio2_3( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Pio2_3<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/pio2_3.hpp>
#include <boost/simd/constant/simd/pio2_3.hpp>

#endif
