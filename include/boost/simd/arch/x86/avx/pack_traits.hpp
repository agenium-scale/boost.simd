//==================================================================================================
/*!
  @file

  Defines AVX functions for SIMD storage used by pack

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_PACK_TRAITS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_PACK_TRAITS_SIMD_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/arch/common/simd/extension_of.hpp>
#include <boost/simd/arch/x86/sse2/pack_traits.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/detail/pack_proxy.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    BOOST_SIMD_DEFINE_PACK_TRAITS(float,  8, __m256,  _mm256_set_ps, _mm256_load_ps, _mm256_set1_ps);
    BOOST_SIMD_DEFINE_PACK_TRAITS(double, 4, __m256d, _mm256_set_pd, _mm256_load_pd, _mm256_set1_pd);

    struct mm256_load_pi {
      template <typename T>
      BOOST_FORCEINLINE __m256i operator()(T const* ptr) const BOOST_NOEXCEPT {
        return _mm256_load_si256(reinterpret_cast<__m256i const*>(ptr));
      }
    };

    // TODO use a static instance instead? Because we're header only there is no proper way to do that?
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T,  4, __m256i, _mm256_set_epi64x, mm256_load_pi{}, _mm256_set1_epi64x);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T,  8, __m256i, _mm256_set_epi32,  mm256_load_pi{}, _mm256_set1_epi32);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T, 16, __m256i, _mm256_set_epi16,  mm256_load_pi{}, _mm256_set1_epi16);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T, 32, __m256i, _mm256_set_epi8,   mm256_load_pi{}, _mm256_set1_epi8);
  }

  namespace ext
  {
    // __m256* storage are supported by AVX hardware
    template<typename Enable> struct extension_of<__m256,Enable>
    {
      using type = ::boost::simd::avx_;
    };

    template<typename Enable> struct extension_of<__m256d,Enable>
    {
      using type = ::boost::simd::avx_;
    };

    template<typename Enable> struct extension_of<__m256i,Enable>
    {
      using type = ::boost::simd::avx_;
    };

    template<typename Enable> struct abi_of<float,8,Enable>
    {
      using type = ::boost::simd::avx_;
    };

    template<typename Enable> struct abi_of<double,4,Enable>
    {
      using type = ::boost::simd::avx_;
    };
  }
} }

#endif
