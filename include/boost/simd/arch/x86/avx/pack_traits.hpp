//==================================================================================================
/*!
  @file

  Defines AVX functions for SIMD storage used by pack

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/arch/x86/sse2/pack_traits.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/pack_traits.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    BOOST_SIMD_DEFINE_PACK_TRAITS(float,  8, __m256 );
    BOOST_SIMD_DEFINE_PACK_TRAITS(double, 4, __m256d);
  }

  namespace ext
  {
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
