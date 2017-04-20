//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOGPI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOGPI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Logpi Logpi (function template)

    Generates value \f$\log\pi\f$

    @headerref{<boost/simd/constant/logpi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Logpi();
        @endcode

    2.  @code
        template<typename T> auto Logpi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Logpi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Logpi<T>();
    @endcode
    is similar to:
    @code
    T r = log(Pi<T>());
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Logpi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Logpi<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/logpi.hpp>
#include <boost/simd/constant/simd/logpi.hpp>

#endif
