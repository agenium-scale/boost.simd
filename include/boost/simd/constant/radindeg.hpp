//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_RADINDEG_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_RADINDEG_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Radindeg Radindeg (function template)

    Generates  degree in radian multiplier, \f$\frac\pi{180}\f$.

    @headerref{<boost/simd/constant/radindeg.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Radindeg();
        @endcode

    2.  @code
        template<typename T> auto Radindeg( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Radindeg constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Radindeg<T>();
    @endcode
    is similar to:
    @code
    T r = Pi<T>()/Ratio<T>(180);
    @endcode
    @see  inrad, indeg, Radindegr, Deginrad

    2.  A value of type @c T so that:
    @code
    T x, r = Radindeg( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Radindeg<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/radindeg.hpp>
#include <boost/simd/constant/simd/radindeg.hpp>

#endif
