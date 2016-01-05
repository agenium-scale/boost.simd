//==================================================================================================
/*!
  @file

  Convenience header for SIMD detection

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_PREDEF_HPP_INCLUDED
#define BOOST_SIMD_SDK_PREDEF_HPP_INCLUDED

/*
  Force the setup of specific SIMD x86 extension on MSVC.

  As MSVC doesn't have /ARCH: option for each special extension in the SSE familly, we emulate
  it via the use of the BOOST_SIMD_HAS_xxx_SUPPORT macro before using Boost.Predef detection
  system.
*/

#if defined(_MSC_VER)
  #if defined(BOOST_SIMD_HAS_SSE3_SUPPORT)
  #define __SSE3__
  #endif

  #if defined(BOOST_SIMD_HAS_SSSE3_SUPPORT)
  #define __SSSE3__
  #endif

  #if defined(BOOST_SIMD_HAS_SSE4_1_SUPPORT)
  #define __SSE4_1__
  #endif

  #if defined(BOOST_SIMD_HAS_SSE4_2_SUPPORT)
  #define __SSE4_2__
  #endif

  #if defined(BOOST_SIMD_HAS_SSE4A_SUPPORT)
  #define __SSE4A__
  #endif

  #if defined(BOOST_SIMD_HAS_XOP_SUPPORT)
  #define __XOP__
  #endif

  #if defined(BOOST_SIMD_HAS_FMA4_SUPPORT)
  #define __FMA4__
  #endif

  #if defined(BOOST_SIMD_HAS_FMA3_SUPPORT)
  #define __FMA3__
  #endif

  #if defined(BOOST_SIMD_HAS_MIC_SUPPORT)
  #define __MIC__
  #endif
#endif

#include <boost/predef/hardware/simd.h>

#endif
