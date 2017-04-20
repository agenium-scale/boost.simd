//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MLOG2TWO2NMB_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MLOG2TWO2NMB_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mlog2two2nmb Mlog2two2nmb (function template)

    Generates constant Mlog2two2nmb.

    @headerref{<boost/simd/constant/mlog2two2nmb.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mlog2two2nmb();
        @endcode

    2.  @code
        template<typename T> auto Mlog2two2nmb( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mlog2two2nmb constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Mlog2two2nmb<T>();
    @endcode
    is similar to:
    @code
      r =  T(Nbmantissabits<T>());
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Mlog2two2nmb( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mlog2two2nmb<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mlog2two2nmb.hpp>
#include <boost/simd/constant/simd/mlog2two2nmb.hpp>

#endif
