//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_NAN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_NAN_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Nan Nan (function template)

  Generates  a Not a Number (Nan) constant with all bits set to one.

  @headerref{<boost/simd/constant/nan.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Nan();
      @endcode

  2.  @code
      template<typename T> auto Nan( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Nan constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A Nan representation for this type, i.e QuietNan (with all bits set to one) for IEEE reals and
  0 for integers.

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/nan.hpp>
#include <boost/simd/constant/simd/nan.hpp>

#endif
