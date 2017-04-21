//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_VALMIN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_VALMIN_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Valmin Valmin (function template)

  Generates the minimum finite representable value of a given type.

  @headerref{<boost/simd/constant/valmin.hpp>}

  @par Description

  1.  @code
    template<typename T> auto Valmin();
    @endcode

  2.  @code
    template<typename T> auto Valmin( boost::simd::as_<T> const& target );
    @endcode

  Generates the minimum finite representable value of a given type
  [as defined by the C++ standard](http://en.cppreference.com/w/cpp/types/numeric_limits/min).

  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to the minimum finite representable value for this type.

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/valmin.hpp>
#include <boost/simd/constant/simd/valmin.hpp>

#endif
