//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_THREEPIO_4_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_THREEPIO_4_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Threepio_4 Threepio_4 (function template)

  Generates \f$3\pi/4\f$

  @headerref{<boost/simd/constant/threepio_4.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Threepio_4();
      @endcode

  2.  @code
      template<typename T> auto Threepio_4( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Threepio_4 constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  1.  A value of type @c T so that:
  @code
  T r = Threepio_4<T>();
  @endcode
  is similar to:
  @code
  T r = Three<T>()*Pi<T>()/Four<T>();
  @endcode

  2.  A value of type @c T so that:
  @code
  T x, r = Threepio_4( boost::simd::as(x));
  @endcode
  is equivalent to:
  @code
  T r = Threepio_4<T>();
  @endcode

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/threepio_4.hpp>
#include <boost/simd/constant/simd/threepio_4.hpp>

#endif
