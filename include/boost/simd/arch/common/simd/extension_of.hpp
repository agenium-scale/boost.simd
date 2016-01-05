//==================================================================================================
/*!
  @file

  Defines the as_simd metafunction for common cases

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_EXTENSION_OF_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_EXTENSION_OF_HPP_INCLUDED

#include <boost/simd/arch/common/tags.hpp>

namespace boost { namespace simd { namespace ext
{
  /*!
    @ingroup  group-ext
    @brief    Type to Extension mapping extension point

    Provide a customizable extension point for SIMD extension type mapping.

    @tparam Type      Type of the elements
    @tparam Extension Architectural tag for target extension
  **/
  template<typename T, typename Enable = void>
  struct extension_of
  {
    using type = boost::simd::simd_emulation_;
  };
} } }

#endif
