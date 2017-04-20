//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TWOOPI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TWOOPI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Twoopi Twoopi (function template)

    Generates \f$\frac2\pi\f$

    @headerref{<boost/simd/constant/twoopi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Twoopi();
        @endcode

    2.  @code
        template<typename T> auto Twoopi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Twoopi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Twoopi<T>();
    @endcode
    is similar to:
    @code
    T r = Two<T>()/Pi<T>();
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Twoopi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Twoopi<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/twoopi.hpp>
#include <boost/simd/constant/simd/twoopi.hpp>

#endif
