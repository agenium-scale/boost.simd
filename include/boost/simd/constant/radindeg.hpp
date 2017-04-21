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

  Generates  degree in radian multiplier, \f$\frac{180}\pi\f$.

  @headerref{<boost/simd/constant/radindeg.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Radindeg();
      @endcode

  2.  @code
      template<typename T> auto Radindeg( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Radindeg constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T  that evaluates to ` T(180)/Pi<T>()`

  @par Requirements
  - **T** models IEEEValue
**/

#include <boost/simd/constant/scalar/radindeg.hpp>
#include <boost/simd/constant/simd/radindeg.hpp>

#endif
