//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_THOUSAND_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_THOUSAND_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Thousand Thousand (function template)

  Generates the constant1000.

  @headerref{<boost/simd/constant/thousand.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Thousand();
      @endcode

  2.  @code
      template<typename T> auto Thousand( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Thousand constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to <tt>T(1000)</tt>.

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/thousand.hpp>
#include <boost/simd/constant/simd/thousand.hpp>

#endif
