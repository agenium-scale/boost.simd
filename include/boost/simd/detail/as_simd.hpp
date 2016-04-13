//==================================================================================================
/*!
  @file

  Defines the as_simd meta-function

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_AS_SIMD_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/arch/spec.hpp>

namespace boost { namespace simd { namespace detail
{
  /*!
    @ingroup  group-detail
    @brief    Extension to Type mapping

    For a given couple @c Type x @c Cardinal, provides type and utility functions to handle data
    block containing @c Cardinal elements of type @c Type in an optimized way.

    @tparam Type      Type of the elements
    @tparam Extension Architectural tag for target extension
  **/
  template<typename Type, typename Extension> struct as_simd : ext::as_simd<Type,Extension> {};
} } }

#endif
