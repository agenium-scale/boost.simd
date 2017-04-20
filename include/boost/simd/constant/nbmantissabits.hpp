//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_NBMANTISSABITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_NBMANTISSABITS_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Nbmantissabits Nbmantissabits (function template)

    Generates the number of mantissa bits of a floating point number.

    @headerref{<boost/simd/constant/nbmantissabits.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Nbmantissabits();
        @endcode

    2.  @code
        template<typename T> auto Nbmantissabits( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Nbmantissabits constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Nbmantissabits<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = sizeof(T)*8
    else if T is double
      r =  52;
    else if is float
      r =  23;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Nbmantissabits( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Nbmantissabits<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/nbmantissabits.hpp>
#include <boost/simd/constant/simd/nbmantissabits.hpp>

#endif
