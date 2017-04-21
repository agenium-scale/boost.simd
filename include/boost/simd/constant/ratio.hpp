//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_RATIO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_RATIO_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Ratio Ratio (function template)

  Generates a constant from a static rational number representation.

  @headerref{<boost/simd/constant/ratio.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Ratio();
      @endcode

  2.  @code
      template<typename T> auto Ratio( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Ratio constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  1.  A value of type @c T so that:
  @code
  T r = Ratio<T>();
  @endcode


  2.  A value of type @c T so that:
  @code
  T x, r = Ratio( boost::simd::as(x));
  @endcode
  is equivalent to:
  @code
  T r = Ratio<T>();
  @endcode

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/ratio.hpp>
#include <boost/simd/constant/simd/ratio.hpp>

#endif
