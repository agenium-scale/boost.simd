//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FACT_6_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FACT_6_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Fact_6 Fact_6 (function template)

    Generates 6! that is 720

    @headerref{<boost/simd/constant/fact_6.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Fact_6();
        @endcode

    2.  @code
        template<typename T> auto Fact_6( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Fact_6 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Fact_6<T>();
    @endcode
    is similar to:
    @code
    T r = T(720);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Fact_6( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Fact_6<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/fact_6.hpp>
#include <boost/simd/constant/simd/fact_6.hpp>

#endif
