//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MINF_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MINF_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Minf Minf (function template)

    Generates the -inf IEEE value (\f$-\infty\f$) for floating types and minimum value
    for integer types

    @headerref{<boost/simd/constant/minf.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Minf();
        @endcode

    2.  @code
        template<typename T> auto Minf( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Minf constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Minf<T>();
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Minf( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Minf<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/minf.hpp>
#include <boost/simd/constant/simd/minf.hpp>

#endif
