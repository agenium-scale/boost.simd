//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MLOGTWO2NMB_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MLOGTWO2NMB_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mlogtwo2nmb Mlogtwo2nmb (function template)

    Generates constant Mlogtwo2nmb.

    @headerref{<boost/simd/constant/mlogtwo2nmb.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mlogtwo2nmb();
        @endcode

    2.  @code
        template<typename T> auto Mlogtwo2nmb( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mlogtwo2nmb constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Mlogtwo2nmb<T>();
    @endcode
    is similar to:
    @code
      r =  -log(exp2(T(Nbmantissabits<T>())));
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Mlogtwo2nmb( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mlogtwo2nmb<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mlogtwo2nmb.hpp>
#include <boost/simd/constant/simd/mlogtwo2nmb.hpp>

#endif
