//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOG_2OLOG_10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOG_2OLOG_10_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Log_2olog_10 Log_2olog_10 (function template)

    nerates constant Log_2olog_10 : \f$\frac{\log(2)}{\log(10)}\f$.

    @headerref{<boost/simd/constant/log_2olog_10.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Log_2olog_10();
        @endcode

    2.  @code
        template<typename T> auto Log_2olog_10( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Log_2olog_10 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Log_2olog_10<T>();
    @endcode
    is similar to:
    @code
      r =  T(0.3010299956639811952137388947244930267681898814621085);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Log_2olog_10( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Log_2olog_10<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/log_2olog_10.hpp>
#include <boost/simd/constant/simd/log_2olog_10.hpp>

#endif
