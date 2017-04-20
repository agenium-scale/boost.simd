//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOG_2_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOG_2_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Log_2 Log_2 (function template)

    Generates constant Log_2 : \f$\log(2)\f$.

    @headerref{<boost/simd/constant/log_2.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Log_2();
        @endcode

    2.  @code
        template<typename T> auto Log_2( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Log_2 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Log_2<T>();
    @endcode
    is similar to:
    @code
      r =  T(0.6931471805599453094172321214581765680755001343602553);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Log_2( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Log_2<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/log_2.hpp>
#include <boost/simd/constant/simd/log_2.hpp>

#endif
