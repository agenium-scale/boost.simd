//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MLOGEPS2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MLOGEPS2_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mlogeps2 Mlogeps2 (function template)

    Generates \f$-\log(eps^2)\f$ value

    @headerref{<boost/simd/constant/mlogeps2.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mlogeps2();
        @endcode

    2.  @code
        template<typename T> auto Mlogeps2( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mlogeps2 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Mlogeps2<T>();
    @endcode
    is similar to:
    @code
    T r = -log(sqr(Eps<T>()));
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Mlogeps2( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mlogeps2<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mlogeps2.hpp>
#include <boost/simd/constant/simd/mlogeps2.hpp>

#endif
