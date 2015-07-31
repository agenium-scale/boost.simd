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

#define BOOST_SIMD_BYTES              32
#define BOOST_SIMD_BITS               256
#define BOOST_SIMD_CARDINALS          (2)(4)(8)(16)(32)
#define BOOST_SIMD_TAG_SEQ            (::boost::simd::avx_)(::boost::simd::sse_)

#ifndef BOOST_SIMD_DEFAULT_EXTENSION
  #define BOOST_SIMD_DEFAULT_EXTENSION  ::boost::simd::avx_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::avx2_

#include <immintrin.h>
#include <boost/simd/arch/x86/sse2/as_simd.hpp>
#include <boost/simd/arch/x86/avx/as_simd.hpp>

#endif
#endif
