//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FACT_5_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FACT_5_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Fact_5 Fact_5 (function template)

    Generates  5!,  that is 120

    @headerref{<boost/simd/constant/fact_5.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Fact_5();
        @endcode

    2.  @code
        template<typename T> auto Fact_5( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Fact_5 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Fact_5<T>();
    @endcode
    is similar to:
    @code
    T r = T(120);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Fact_5( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Fact_5<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/fact_5.hpp>
#include <boost/simd/constant/simd/fact_5.hpp>

#endif
