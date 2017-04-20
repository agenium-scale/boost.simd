//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MNINE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MNINE_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Mnine Mnine (function template)

    Generates T(9).

    @headerref{<boost/simd/constant/mnine.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Mnine();
        @endcode

    2.  @code
        template<typename T> auto Mnine( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Mnine constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = T(-9);
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Mnine( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Mnine<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/mnine.hpp>
#include <boost/simd/constant/simd/mnine.hpp>

#endif
