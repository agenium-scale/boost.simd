//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INVSQRT_2PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INVSQRT_2PI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Invsqrt_2pi Invsqrt_2pi (function template)

    Constant  \f$\frac1{\sqrt{2\pi}}\f$.

    @headerref{<boost/simd/constant/invsqrt_2pi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Invsqrt_2pi();
        @endcode

    2.  @code
        template<typename T> auto Invsqrt_2pi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Invsqrt_2pi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Invsqrt_2pi<T>();
    @endcode
    is similar to:
    @code
    T r = rsqrt(Two<T>()*Pi<T>());
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Invsqrt_2pi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Invsqrt_2pi<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/invsqrt_2pi.hpp>
#include <boost/simd/constant/simd/invsqrt_2pi.hpp>

#endif
