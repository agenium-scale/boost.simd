//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SQRT_2PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SQRT_2PI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Sqrt_2pi Sqrt_2pi (function template)

    Generates  \f$\sqrt{2\pi}\f$.

    @headerref{<boost/simd/constant/sqrt_2pi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Sqrt_2pi();
        @endcode

    2.  @code
        template<typename T> auto Sqrt_2pi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Sqrt_2pi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Sqrt_2pi<T>();
    @endcode
    is similar to:
    @code
    T r = sqrt(Pix2<T>();
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Sqrt_2pi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Sqrt_2pi<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/sqrt_2pi.hpp>
#include <boost/simd/constant/simd/sqrt_2pi.hpp>

#endif
