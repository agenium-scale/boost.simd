//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TWOPI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TWOPI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Twopi Twopi (function template)

    Generates \f$2\pi\f$

    @headerref{<boost/simd/constant/twopi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Twopi();
        @endcode

    2.  @code
        template<typename T> auto Twopi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Twopi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Twopi<T>();
    @endcode
    is similar to:
    @code
    T r = Two<T>()*Pi<T>();
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Twopi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Twopi<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/twopi.hpp>
#include <boost/simd/constant/simd/twopi.hpp>

#endif
