//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_THOUSAND_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_THOUSAND_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Thousand Thousand (function template)

    Generates 1000.

    @headerref{<boost/simd/constant/thousand.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Thousand();
        @endcode

    2.  @code
        template<typename T> auto Thousand( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Thousand constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r =T(1000)
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Thousand( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Thousand<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/thousand.hpp>
#include <boost/simd/constant/simd/thousand.hpp>

#endif
