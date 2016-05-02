//==================================================================================================
/*!
  @file

  Defines MIC functions for SIMD storage used by pack

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_MIC_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_MIC_PACK_TRAITS_HPP_INCLUDED

#include <cassert>
#include <boost/simd/arch/x86/avx/pack_traits.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    BOOST_SIMD_DEFINE_PACK_TRAITS(float, 16, __m512,  _mm512_set_ps, _mm512_load_ps, _mm512_set1_ps);
    BOOST_SIMD_DEFINE_PACK_TRAITS(double, 8, __m512d, _mm512_set_pd, _mm512_load_pd, _mm512_set1_pd);

    template <typename... Args>
    void _mm512_TODO(Args const&...)
    {
      assert(false);
    }

    struct mm512_load_si512_auto {
      template <typename T>
      BOOST_FORCEINLINE __m512i operator()(T const* ptr) const BOOST_NOEXCEPT {
        return _mm512_load_si512(reinterpret_cast<__m512i const*>(ptr));
      }
    };

    // TODO use a static instance instead? Because we're header only there is no proper way to do that?
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T,  8, __m512i, _mm512_set_epi64, mm512_load_si512_auto(), _mm512_set1_epi64);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T, 16, __m512i, _mm512_set_epi32, mm512_load_si512_auto(), _mm512_set1_epi32);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T, 32, __m512i, _mm512_TODO,      mm512_load_si512_auto(), _mm512_set1_epi16);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T, 64, __m512i, _mm512_TODO,      mm512_load_si512_auto(), _mm512_set1_epi8);
  }

  namespace ext
  {
    // __m512* storage are supported by MIC hardware
    template<typename Enable> struct abi_of<__m512d,Enable>
    {
      using type = ::boost::simd::mic_;
    };

    template<typename Enable> struct abi_of<__m512,Enable>
    {
      using type = ::boost::simd::mic_;
    };

    template<typename Enable> struct abi_of<__m512i,Enable>
    {
      using type = ::boost::simd::mic_;
    };
  }
} }

#endif
