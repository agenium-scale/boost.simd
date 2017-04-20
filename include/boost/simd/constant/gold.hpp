//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_GOLD_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_GOLD_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Gold Gold (function template)

    Generates the golden ratio that is \f$\phi = \frac{1+\sqrt5}{2}\f$

    @headerref{<boost/simd/constant/gold.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Gold();
        @endcode

    2.  @code
        template<typename T> auto Gold( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Gold constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Gold<T>();
    @endcode
    is similar for floating types to:
    @code
    T r = (1+sqrt(T(5)))/2;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Gold( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Gold<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/gold.hpp>
#include <boost/simd/constant/simd/gold.hpp>

#endif
