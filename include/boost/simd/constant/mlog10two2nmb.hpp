//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MLOG10TWO2NMB_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MLOG10TWO2NMB_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mlog10two2nmb Mlog10two2nmb (function template)

    Generates constant Mlog10two2nmb.

    @headerref{<boost/simd/constant/mlog10two2nmb.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mlog10two2nmb();
        @endcode

    2.  @code
        template<typename T> auto Mlog10two2nmb( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mlog10two2nmb constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Mlog10two2nmb<T>();
    @endcode
    is similar to:
    @code
      r =  -log10(exp2(T(Nbmantissabits<T>())));
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Mlog10two2nmb( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mlog10two2nmb<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mlog10two2nmb.hpp>
#include <boost/simd/constant/simd/mlog10two2nmb.hpp>

#endif
