//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_EPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_EPS_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Eps Eps (function template)

   Generates a value of the chosen type equals to the difference between 1 and the next
  representable value of the chosen type.

  @headerref{<boost/simd/constant/eps.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Eps();
      @endcode

  2.  @code
      template<typename T> auto Eps( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Eps constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to  `std::numeric_limits<boost::dispatch::scalar_of_t<T>>::epsilon()` is @c T
  is floating and 1 if @c T is integral.

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/eps.hpp>
#include <boost/simd/constant/simd/eps.hpp>

#endif
