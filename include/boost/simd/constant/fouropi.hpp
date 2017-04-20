//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FOUROPI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FOUROPI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Fouropi Fouropi (function template)

    Constant \f$\frac4\pi\f$.

    @headerref{<boost/simd/constant/fouropi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Fouropi();
        @endcode

    2.  @code
        template<typename T> auto Fouropi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Fouropi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Fouropi<T>();
    @endcode
    is similar to:
    @code
    T r = Four<T>()/Pi<T>();
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Fouropi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Fouropi<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/fouropi.hpp>
#include <boost/simd/constant/simd/fouropi.hpp>

#endif
