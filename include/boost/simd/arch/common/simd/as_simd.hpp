//==================================================================================================
/*!
  @file

  Defines the as_simd metafunction for common cases

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_COMMON_SIMD_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_COMMON_SIMD_AS_SIMD_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd { namespace ext
{
  /*!
    @ingroup  group-ext
    @brief    Extension to Type mapping extension point

    Provide a customizable extension point for SIMD extension type mapping.

    @tparam Type      Type of the elements
    @tparam Extension Architectural tag for target extension
  **/
  template<typename T, typename Extension, typename Enable = void>
  struct as_simd
  {
    using type = brigand::no_such_type_;
  };
} } }

#endif
