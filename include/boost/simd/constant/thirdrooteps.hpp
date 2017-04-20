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

    1. and 2.  return a value of type @c T containing the Thirdrooteps constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Thirdrooteps<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = 1
    else if T is double
      r =  6.055454452393343e-06;
    else if T is float
      r =  4.9215667e-03 ;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Thirdrooteps( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Thirdrooteps<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/thirdrooteps.hpp>
#include <boost/simd/constant/simd/thirdrooteps.hpp>

#endif
