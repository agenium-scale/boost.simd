//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MZERO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MZERO_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Mzero Mzero (function template)

  Generates constant @c -0.

  @headerref{<boost/simd/constant/mzero.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Mzero();
      @endcode

  2.  @code
      template<typename T> auto Mzero( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Mzero constant.

  @par Note

  - this constant for floting types is the second IEEE representation of 0. if @c T is a floating type
    `T(1)/Mezro<T>()` is `Minf<T>()`.

  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to `T(-0.0)`

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/mzero.hpp>
#include <boost/simd/constant/simd/mzero.hpp>

#endif
