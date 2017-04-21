//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SIGNMASK_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SIGNMASK_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Signmask Signmask (function template)

  Generates a mask with the lone most significand bit set to one
  (even if the type is unsigned).

  @headerref{<boost/simd/constant/signmask.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Signmask();
      @endcode

  2.  @code
      template<typename T> auto Signmask( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Signmask constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to `bitwise_cast<T>(1 << sizeof(T)*8-1)`

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/signmask.hpp>
#include <boost/simd/constant/simd/signmask.hpp>

#endif
