//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TWOTOM10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TWOTOM10_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Twotom10 Twotom10 (function template)

    Generates 2 to the power -10 (\f$2^{-10}\f$)

    @headerref{<boost/simd/constant/twotom10.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Twotom10();
        @endcode

    2.  @code
        template<typename T> auto Twotom10( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Twotom10 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Twotom10<T>();
    @endcode
    is similar to:
    @code
    T r = pow(2, -10);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Twotom10( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Twotom10<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/twotom10.hpp>
#include <boost/simd/constant/simd/twotom10.hpp>

#endif
