//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_CONSTANT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_CONSTANT_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Constant Constant (function template)

  Generates a constant defined by a bit pattern.

  @headerref{<boost/simd/constant/constant.hpp>}

  @par Description

  1.  @code
    template<typename T, std::uintmax_t N> T Constant();
    @endcode

  Generates a constant that evaluate to a value of type @c T which bits pattern is defined by
  the Integral Constant @c N.

  @par Type Parameters

  | Name                | Description                                              |
  |--------------------:|:---------------------------------------------------------|
  | **T**               | type of the generated constant                           |
  | **N**               | bits pattern holding the value of the generated constant |

  @par Return Value
  A value of type @c T so that <tt>bitwise_cast<as_integer<T>>(Constant<T,N>()) == N</tt>
  evaluates to @ true.

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/definition/constant.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_generator.hpp>
#include <boost/simd/arch/common/simd/constant/constant_generator.hpp>

#endif
