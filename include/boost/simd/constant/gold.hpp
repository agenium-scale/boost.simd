//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_GOLD_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_GOLD_HPP_INCLUDED



/*!
  @ingroup group-constant
  @defgroup constant-Gold Gold (function template)

  Generates the golden ratio that is \f$\phi = \frac{1+\sqrt5}{2}\f$

  @headerref{<boost/simd/constant/gold.hpp>}

  @par Description

  1.  @code
      template<typename T> auto Gold();
      @endcode

  2.  @code
      template<typename T> auto Gold( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T containing the Gold constant.


  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T  that evaluates to <tt>T((1 + sqrt(5))/2)</tt>.

  @par Requirements
  - **T** models IEEEValue
**/

#include <boost/simd/constant/scalar/gold.hpp>
#include <boost/simd/constant/simd/gold.hpp>

#endif
