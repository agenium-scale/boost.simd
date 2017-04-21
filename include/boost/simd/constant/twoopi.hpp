//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TWOOPI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TWOOPI_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Twoopi Twoopi (function template)

  Generates \f$\frac2\pi\f$

  @headerref{<boost/simd/constant/twoopi.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Twoopi();
      @endcode

  2.  @code
      template<typename T> auto Twoopi( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Twoopi constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to <tt>Two<T>()/Pi<T>()</tt>.

  @par Requirements
  - **T** models IEEEValue
**/

#include <boost/simd/constant/scalar/twoopi.hpp>
#include <boost/simd/constant/simd/twoopi.hpp>

#endif
