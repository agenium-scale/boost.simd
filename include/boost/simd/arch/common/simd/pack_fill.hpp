//==================================================================================================
/*!
  @file

  Defines generic `fill` functions for SIMD storage used by pack

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================

#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_PACK_FILL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_PACK_FILL_HPP_INCLUDED

#include <array>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template <typename T, std::size_t N, typename... Ts>
  BOOST_FORCEINLINE static void pack_fill(std::array<T, N>& d, Ts const&... v)
  {
    d = std::array<T, N>{{ static_cast<T>(v)... }};
  }
} } }

#endif
