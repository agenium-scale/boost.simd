//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_FOURPI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_FOURPI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Fourpi Fourpi (function template)

    Constant \f$4\pi\f$.

    @headerref{<boost/simd/constant/fourpi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Fourpi();
        @endcode

    2.  @code
        template<typename T> auto Fourpi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Fourpi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Fourpi<T>();
    @endcode
    is similar to:
    @code
    T r = Four<T>()*Pi<T>();
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Fourpi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Fourpi<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/fourpi.hpp>
#include <boost/simd/constant/simd/fourpi.hpp>

#endif
