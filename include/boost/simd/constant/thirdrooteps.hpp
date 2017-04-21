//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_THIRDROOTEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_THIRDROOTEPS_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Thirdrooteps Thirdrooteps (function template)

  Generates the cubic root of [Eps](@ref constant-Eps).

  @headerref{<boost/simd/constant/thirdrooteps.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Thirdrooteps();
      @endcode

  2.  @code
      template<typename T> auto Thirdrooteps( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Thirdrooteps constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to

  | Type                | double                              | float             |    Integral     |
  |--------------------:|:------------------------------------|-------------------|-----------------|
  | value               |   6.055454452393343e-06             |  4.9215667e-03f   |   1             |

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/thirdrooteps.hpp>
#include <boost/simd/constant/simd/thirdrooteps.hpp>

#endif
