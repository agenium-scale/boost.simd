//==================================================================================================
/*!
  @file

  Defines SSE2 functions for SIMD storage used by pack

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================

#ifndef BOOST_SIMD_ARCH_X86_SSE2_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/arch/common/simd/extension_of.hpp>
#include <boost/simd/arch/x86/sse1/pack_traits.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/detail/pack_proxy.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    BOOST_SIMD_DEFINE_PACK_TRAITS(double, 2, __m128d, _mm_set_pd, _mm_load_pd, _mm_set1_pd);

    struct mm_load_pi {
      template <typename T>
      BOOST_FORCEINLINE __m128i operator()(T const* ptr) const BOOST_NOEXCEPT {
        return _mm_load_si128(reinterpret_cast<__m128i const*>(ptr));
      }
    };

    // TODO use a static instance instead? Because we're header only there is no proper way to do that?
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T,  2, __m128i, _mm_set_epi64x, mm_load_pi{}, _mm_set1_epi64x);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T,  4, __m128i, _mm_set_epi32,  mm_load_pi{}, _mm_set1_epi32);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T,  8, __m128i, _mm_set_epi16,  mm_load_pi{}, _mm_set1_epi16);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T, 16, __m128i, _mm_set_epi8,   mm_load_pi{}, _mm_set1_epi8);
  }

  namespace ext
  {
    // __m128* storage are supported by SSE hardware
    template<typename Enable> struct extension_of<__m128i,Enable>
    {
      using type = ::boost::simd::sse_;
    };

    template<typename Enable> struct extension_of<__m128d,Enable>
    {
      using type = ::boost::simd::sse_;
    };
  }
} }

#endif
