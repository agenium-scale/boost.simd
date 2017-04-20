//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MFOUR_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MFOUR_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mfour Mfour (function template)

    Generates -4.

    @headerref{<boost/simd/constant/mfour.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mfour();
        @endcode

    2.  @code
        template<typename T> auto Mfour( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mfour constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = T(-4);
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Mfour( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mfour<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mfour.hpp>
#include <boost/simd/constant/simd/mfour.hpp>

#endif
