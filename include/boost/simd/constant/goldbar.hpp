//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_GOLDBAR_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_GOLDBAR_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Goldbar Goldbar (function template)

    Generates the conjugate golden ratio that is \f$\bar\phi = \frac{1-\sqrt5}{2}\f$

    @headerref{<boost/simd/constant/goldbar.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Goldbar();
        @endcode

    2.  @code
        template<typename T> auto Goldbar( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Goldbar constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Goldbar<T>();
    @endcode
    is similar for floating types to:
    @code
    T r = (1-sqrt(T(5)))/2;
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Goldbar( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Goldbar<T>();
    @endcode

    @par Requirements
    - **T** models Value
  **/

#include <boost/simd/constant/scalar/goldbar.hpp>
#include <boost/simd/constant/simd/goldbar.hpp>

#endif
