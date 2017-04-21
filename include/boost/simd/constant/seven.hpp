//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SEVEN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SEVEN_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Seven Seven (function template)

  Generates the constant@c 7

  @headerref{<boost/simd/constant/seven.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Seven();
      @endcode

  2.  @code
      template<typename T> auto Seven( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Seven constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to `T(7)`

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/seven.hpp>
#include <boost/simd/constant/simd/seven.hpp>

#endif
