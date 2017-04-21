//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INV2PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INV2PI_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Inv2pi Inv2pi (function template)

   Generates the constant\f$\frac1{2\pi}\f$.

  @headerref{<boost/simd/constant/inv2pi.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Inv2pi();
      @endcode

  2.  @code
      template<typename T> auto Inv2pi( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Inv2pi constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to `rec(Two<T>()*Pi<T>())`.

  @par Requirements
  - **T** models IEEEValue
**/

#include <boost/simd/constant/scalar/inv2pi.hpp>
#include <boost/simd/constant/simd/inv2pi.hpp>

#endif
