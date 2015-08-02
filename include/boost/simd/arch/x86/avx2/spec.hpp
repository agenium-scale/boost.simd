//==================================================================================================
/*!
  @file

  Defines the AVX2 specifications

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SPEC_HPP_INCLUDED

#include <boost/simd/sdk/predef.hpp>

#if BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_AVX2_VERSION

#ifndef BOOST_SIMD_DEFAULT_FAMILY
  #define BOOST_SIMD_DEFAULT_FAMILY  ::boost::simd::avx_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::avx2_

#include <immintrin.h>
#include <boost/simd/arch/x86/sse2/as_simd.hpp>
#include <boost/simd/arch/x86/avx/as_simd.hpp>

#endif
#endif
