//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_NBMANTISSABITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_NBMANTISSABITS_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Nbmantissabits Nbmantissabits (function template)

  Generates the number of mantissa bits of a floating point number.

  @headerref{<boost/simd/constant/nbmantissabits.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Nbmantissabits();
      @endcode

  2.  @code
      template<typename T> auto Nbmantissabits( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c as_integer_t<T> containing the Nbmantissabits constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c as_integer_t<T> that evaluates to

  | Type                | double                        | float         | Integral        |
  |--------------------:|:------------------------------|---------------|-----------------|
  | value               |   52                          |      23       | sizeof(T)*8     |


  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/nbmantissabits.hpp>
#include <boost/simd/constant/simd/nbmantissabits.hpp>

#endif
