//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SQRTVALMAX_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SQRTVALMAX_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Sqrtvalmax Sqrtvalmax (function template)

  Generates the square root of the greatest finite representable value.

  @headerref{<boost/simd/constant/sqrtvalmax.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Sqrtvalmax();
      @endcode

  2.  @code
      template<typename T> auto Sqrtvalmax( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Sqrtvalmax constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  1.  A value of type @c T that evaluates to `sqrt(Valmax<T>()`

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/sqrtvalmax.hpp>
#include <boost/simd/constant/simd/sqrtvalmax.hpp>

#endif
