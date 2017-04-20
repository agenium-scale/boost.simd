//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_NAN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_NAN_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Nan Nan (function template)

    Generates  the Not a Number (Nan) constant..

    @headerref{<boost/simd/constant/nan.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Nan();
        @endcode

    2.  @code
        template<typename T> auto Nan( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Nan constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Nan<T>();
    @endcode
    return the Nan representation for this type, i.e QuietNan for IEEE reals and
    0 for integers.

    2.  A value of type @c T so that:
    @code
    T x, r = Nan( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Nan<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/nan.hpp>
#include <boost/simd/constant/simd/nan.hpp>

#endif
