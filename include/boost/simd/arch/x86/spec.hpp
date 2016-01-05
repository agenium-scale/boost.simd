//==================================================================================================
/*!
  @file

  Gather informations for x86 SIMD extensions

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SPEC_HPP_INCLUDED

#include <boost/predef/architecture.h>

#include <boost/simd/arch/x86/mic/spec.hpp>
#include <boost/simd/arch/x86/avx2/spec.hpp>
#include <boost/simd/arch/x86/fma3/spec.hpp>
#include <boost/simd/arch/x86/xop/spec.hpp>
#include <boost/simd/arch/x86/fma4/spec.hpp>
#include <boost/simd/arch/x86/avx/spec.hpp>
#include <boost/simd/arch/x86/sse4a/spec.hpp>
#include <boost/simd/arch/x86/sse42/spec.hpp>
#include <boost/simd/arch/x86/sse41/spec.hpp>
#include <boost/simd/arch/x86/ssse3/spec.hpp>
#include <boost/simd/arch/x86/sse3/spec.hpp>
#include <boost/simd/arch/x86/sse2/spec.hpp>
#include <boost/simd/arch/x86/sse1/spec.hpp>

// Defines register count macros for X86 CPUs
#if BOOST_HW_SIMD_X86
  #if BOOST_SIMD_ARCH_X86_64
    #if !defined(BOOST_SIMD_GPR_COUNT)
    #define BOOST_SIMD_GPR_COUNT 16u
    #endif

    #if !defined(BOOST_SIMD_VR_COUNT)
    #define BOOST_SIMD_VR_COUNT  16u
    #endif
  #else
    #if !defined(BOOST_SIMD_GPR_COUNT)
    #define BOOST_SIMD_GPR_COUNT 8u
    #endif

    #if !defined(BOOST_SIMD_VR_COUNT)
    #define BOOST_SIMD_VR_COUNT  8u
    #endif
  #endif
#endif

#endif
