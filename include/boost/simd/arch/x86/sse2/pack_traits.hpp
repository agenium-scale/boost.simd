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
#include <type_traits>

namespace boost { namespace simd
{
  namespace detail
  {
    BOOST_SIMD_DEFINE_PACK_TRAITS(double, 2, __m128d);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T,  2, __m128i);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T,  4, __m128i);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T,  8, __m128i);
    BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(typename T, T, 16, __m128i);
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

    template<typename Enable> struct abi_of<double,2,Enable>
    {
      using type = ::boost::simd::sse_;
    };

    template<typename T, std::size_t N>
    struct abi_of<  T, N
                  , typename std::enable_if<   std::is_integral<T>::value
                                            && (N*sizeof(T) == 16)
                                            >::type
                  >
    {
      using type = ::boost::simd::sse_;
    };
  }
} }

#endif
