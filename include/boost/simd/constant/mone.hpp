//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MONE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MONE_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mone Mone (function template)

    Generates -1

    @headerref{<boost/simd/constant/mone.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mone();
        @endcode

    2.  @code
        template<typename T> auto Mone( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mone constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = T(-1);
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Mone( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mone<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mone.hpp>
#include <boost/simd/constant/simd/mone.hpp>

#endif
