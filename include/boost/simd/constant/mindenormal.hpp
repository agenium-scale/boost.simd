//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MINDENORMAL_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MINDENORMAL_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mindenormal Mindenormal (function template)

    Generates the least of all non zero positive value including denormals

    @headerref{<boost/simd/constant/mindenormal.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mindenormal();
        @endcode

    2.  @code
        template<typename T> auto Mindenormal( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mindenormal constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Mindenormal<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = T(1)
    else if T is double
      r =  4.940656458412465e-324;
    else if T is float
      r = 1.4012985e-45;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Mindenormal( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mindenormal<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mindenormal.hpp>
#include <boost/simd/constant/simd/mindenormal.hpp>

#endif
