//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INVLOG10_2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INVLOG10_2_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Invlog10_2 Invlog10_2 (function template)

    Generates constant \f$1/\log10(2)\f$.

    @headerref{<boost/simd/constant/invlog10_2.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Invlog10_2();
        @endcode

    2.  @code
        template<typename T> auto Invlog10_2( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Invlog10_2 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Invlog10_2<T>();
    @endcode
    is similar to:
    @code
    T r =  T(3.32192809488736234787031942949);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Invlog10_2( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Invlog10_2<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/invlog10_2.hpp>
#include <boost/simd/constant/simd/invlog10_2.hpp>

#endif
