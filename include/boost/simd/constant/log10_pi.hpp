//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOG10_PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOG10_PI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Log10_pi Log10_pi (function template)

    Generates base ten logarithm of pi (\f$\log\!10(\pi)\f$)

    @headerref{<boost/simd/constant/log10_pi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Log10_pi();
        @endcode

    2.  @code
        template<typename T> auto Log10_pi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Log10_pi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Log10_pi<T>();
    @endcode
    is similar to:
    @code
    T r = log10(Pi<T>());
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Log10_pi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Log10_pi<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/log10_pi.hpp>
#include <boost/simd/constant/simd/log10_pi.hpp>

#endif
