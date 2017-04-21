//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_GREATESTNONINTEGER_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_GREATESTNONINTEGER_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Greatestnoninteger Greatestnoninteger (function template)

  Generates the greatest non integral value which is exactly
  representable in the type and
  equal to its integral successor.

  All floating numbers greater than `Greatestnoninteger` are integral.

  @headerref{<boost/simd/constant/greatestnoninteger.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Greatestnoninteger();
      @endcode

  2.  @code
      template<typename T> auto Greatestnoninteger( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Greatestnoninteger constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c as_integer_t<T> that evaluates to

  | Type                | double                        | float         |
  |--------------------:|:------------------------------|---------------|
  | value               |   4503599627370495.5          | 8388607.5f    |

  @par Requirements
  - **T** models IEEEValue
**/

#include <boost/simd/constant/scalar/greatestnoninteger.hpp>
#include <boost/simd/constant/simd/greatestnoninteger.hpp>

#endif
