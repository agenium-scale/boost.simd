//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TWOTO31_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TWOTO31_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Twoto31 Twoto31 (function template)

    Generates  2 to the power 31 (\f$2^{31}\f$)

    @headerref{<boost/simd/constant/twoto31.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Twoto31();
        @endcode

    2.  @code
        template<typename T> auto Twoto31( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Twoto31 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Twoto31<T>();
    @endcode
    is similar to:
    @code
    T r = pow(2, 31);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Twoto31( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Twoto31<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/twoto31.hpp>
#include <boost/simd/constant/simd/twoto31.hpp>

#endif
