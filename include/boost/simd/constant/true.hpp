//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TRUE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TRUE_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-True True (function template)

  Generates a value of the logical type associated to the chosen type equal to @c true

  @headerref{<boost/simd/constant/true.hpp>}

  @par Description

  1.  @code
      template<typename T> auto True();
      @endcode

  2.  @code
      template<typename T> auto True( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the True constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  1.  A value of type @c T so that:
  @code
  T r = True<T>();
  @endcode


  2.  A value of type @c T so that:
  @code
  T x, r = True( boost::simd::as(x));
  @endcode
  is equivalent to:
  @code
  T r = True<T>();
  @endcode

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/true.hpp>
#include <boost/simd/constant/simd/true.hpp>

#endif
