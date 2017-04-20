//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FACT_8_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FACT_8_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Fact_8 Fact_8 (function template)

    Generates 8! that is 40320

    @headerref{<boost/simd/constant/fact_8.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Fact_8();
        @endcode

    2.  @code
        template<typename T> auto Fact_8( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Fact_8 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Fact_8<T>();
    @endcode
    is similar to:
    @code
    T r = T(40320);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Fact_8( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Fact_8<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/fact_8.hpp>
#include <boost/simd/constant/simd/fact_8.hpp>

#endif
