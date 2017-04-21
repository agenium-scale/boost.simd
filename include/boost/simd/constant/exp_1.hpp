//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_EXP_1_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_EXP_1_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Exp_1 Exp_1 (function template)

  Generates constant e base of the atural logarithms.

  @headerref{<boost/simd/constant/exp_1.hpp>}

  @par Description

  1.  @code
    template<typename T> auto Exp_1();
    @endcode

  2.  @code
    template<typename T> auto Exp_1( boost::simd::as_<T> const& target );
    @endcode

  Generates a value of type @c T containing the Exp_1 constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  1.  A value of type @c T so that:
  @code
  T r = Exp_1<T>();
  @endcode
  is similar to:
  @code
  r =  T(2.71828182845904523536028747135266249775724709369995);
  @endcode

  2.  A value of type @c T so that:
  @code
  T x, r = Exp_1( boost::simd::as(x));
  @endcode
  is equivalent to:
  @code
  T r = Exp_1<T>();
  @endcode

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/exp_1.hpp>
#include <boost/simd/constant/simd/exp_1.hpp>

#endif
