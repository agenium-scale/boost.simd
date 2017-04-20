//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOGSQRT2PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOGSQRT2PI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Logsqrt2pi Logsqrt2pi (function template)

    Generates value \f$\log\sqrt{2\pi}\f$

    @headerref{<boost/simd/constant/logsqrt2pi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Logsqrt2pi();
        @endcode

    2.  @code
        template<typename T> auto Logsqrt2pi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Logsqrt2pi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Logsqrt2pi<T>();
    @endcode
    is similar to:
    @code
    T r = log(sqrt(2*Pi<T>());
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Logsqrt2pi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Logsqrt2pi<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/logsqrt2pi.hpp>
#include <boost/simd/constant/simd/logsqrt2pi.hpp>

#endif
