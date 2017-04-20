//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MZERO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MZERO_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mzero Mzero (function template)

    Generates -0.

    @headerref{<boost/simd/constant/mzero.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mzero();
        @endcode

    2.  @code
        template<typename T> auto Mzero( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mzero constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Mzero<T>();
    @endcode
    is similar to:
    @code
    T r = -T(0);
    @endcode
    @ par Note:
    This is a special constant as it can be used and considered
    identical to zero, except that for floating point numbers,
    there is two different representation of zero with different bit of sign.
    The existence of the sign can be used in special circumstances as
    choosing between \f$+\infty\f$ and \f$-\infty\f$ instead of nan in computing 1/0.
    \par
    The sign of zero can be accessed through the [is_negative](@ref is_negative)
    and [is_positive](@ref is_positive) predicates or the [bitofsign](@ref bitofsign) functions.

    2.  A value of type @c T so that:
    @code
    T x, r = Mzero( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mzero<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mzero.hpp>
#include <boost/simd/constant/simd/mzero.hpp>

#endif
