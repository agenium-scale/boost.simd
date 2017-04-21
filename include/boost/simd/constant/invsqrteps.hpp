//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INVSQRTEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INVSQRTEPS_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Invsqrteps Invsqrteps (function template)

  Generates value \f$1/{\sqrt\epsilon\}f$

  @headerref{<boost/simd/constant/invsqrteps.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Invsqrteps();
      @endcode

  2.  @code
      template<typename T> auto Invsqrteps( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Invsqrteps constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to `rec(sqrt(Eps<T>())`.

  @par Requirements
  - **T** models IEEEValue
**/

#include <boost/simd/constant/scalar/invsqrteps.hpp>
#include <boost/simd/constant/simd/invsqrteps.hpp>

#endif
