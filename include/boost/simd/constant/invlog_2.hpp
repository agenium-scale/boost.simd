//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INVLOG_2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INVLOG_2_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Invlog_2 Invlog_2 (function template)

  Generates constant \f$1/\log(2)\f$.

  @headerref{<boost/simd/constant/invlog_2.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Invlog_2();
      @endcode

  2.  @code
      template<typename T> auto Invlog_2( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Invlog_2 constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  1.  A value of type @c T so that:
  @code
  T r = Invlog_2<T>();
  @endcode
  is similar to:
  @code
   r =  T(1.442695040888963407359924681001892137426645954152986);
  @endcode

  2.  A value of type @c T so that:
  @code
  T x, r = Invlog_2( boost::simd::as(x));
  @endcode
  is equivalent to:
  @code
  T r = Invlog_2<T>();
  @endcode

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/invlog_2.hpp>
#include <boost/simd/constant/simd/invlog_2.hpp>

#endif
