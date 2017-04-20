//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MTEN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MTEN_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mten Mten (function template)

    Generates -10

    @headerref{<boost/simd/constant/mten.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mten();
        @endcode

    2.  @code
        template<typename T> auto Mten( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mten constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = T(-10)
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Mten( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mten<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mten.hpp>
#include <boost/simd/constant/simd/mten.hpp>

#endif
