//==================================================================================================
/*!
  @file

  Convenience header for SIMD detection

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_PREDEF_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_PREDEF_HPP_INCLUDED

/*
  Force the setup of specific SIMD x86 extension on MSVC.

  As MSVC doesn't have /ARCH: option for each special extension in the SSE familly, we emulate
  it via the use of the BOOST_SIMD_HAS_xxx_SUPPORT macro before using Boost.Predef detection
  system.
*/

#if defined(_MSC_VER)
  #if defined(BOOST_SIMD_ASSUME_SSE3)
    #define __SSE3__
  #endif

  #if defined(BOOST_SIMD_ASSUME_SSSE3)
    #define __SSSE3__
  #endif

  #if defined(BOOST_SIMD_ASSUME_SSE4_1)
    #define __SSE4_1__
  #endif

  #if defined(BOOST_SIMD_ASSUME_SSE4_2)
    #define __SSE4_2__
  #endif

  #if defined(BOOST_SIMD_ASSUME_SSE4A)
    #define __SSE4A__
  #endif

  #if defined(BOOST_SIMD_ASSUME_XOP)
    #define __XOP__
  #endif

  #if defined(BOOST_SIMD_ASSUME_FMA4)
    #define __FMA4__
  #endif

  #if defined(BOOST_SIMD_ASSUME_FMA3)
    #define __FMA3__
  #endif

  #if defined(BOOST_SIMD_ASSUME_MIC)
    #define __MIC__
  #endif
#endif

#include <boost/predef/hardware/simd.h>

// Ensure a cross X86/AMD selection
#if BOOST_HW_SIMD_X86 > BOOST_HW_SIMD_X86_AMD
  #define BOOST_HW_SIMD_X86_OR_AMD BOOST_HW_SIMD_X86
#else
  #define BOOST_HW_SIMD_X86_OR_AMD BOOST_HW_SIMD_X86_AMD
#endif

#if defined(BOOST_HW_SIMD_X86_AVAILABLE) || defined(BOOST_HW_SIMD_X86_AMD_AVAILABLE)
  #define BOOST_HW_SIMD_X86_OR_AMD_AVAILABLE
#endif

#endif
