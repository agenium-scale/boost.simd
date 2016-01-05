//==================================================================================================
/*!
  @file

  Defines SSE1 functions for SIMD storage used by pack

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================

#ifndef BOOST_SIMD_ARCH_X86_SSE1_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/detail/pack_proxy.hpp>
#include <boost/simd/arch/common/simd/extension_of.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    BOOST_SIMD_DEFINE_PACK_TRAITS(float, 4, __m128, _mm_set_ps, _mm_load_ps, _mm_set1_ps);
  }

  namespace ext
  {
    // __m128 storage are supported by SSE hardware
    template<typename Enable> struct extension_of<__m128,Enable>
    {
      using type = ::boost::simd::sse_;
    };
  }
} }

#endif
