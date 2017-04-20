//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INVLOG_10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INVLOG_10_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Invlog_10 Invlog_10 (function template)

    enerates constant \f$1/\log(10)\f$.

    @headerref{<boost/simd/constant/invlog_10.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Invlog_10();
        @endcode

    2.  @code
        template<typename T> auto Invlog_10( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Invlog_10 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Invlog_10<T>();
    @endcode
    is similar to:
    @code
    r =  T(0.4342944819032518276511289189166050822943970058036666);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Invlog_10( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Invlog_10<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/invlog_10.hpp>
#include <boost/simd/constant/simd/invlog_10.hpp>

#endif
