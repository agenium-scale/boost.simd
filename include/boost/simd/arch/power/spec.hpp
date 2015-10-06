//==================================================================================================
/*!
  @file

  Gather informations for PowerPC SIMD extensions

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_SPEC_HPP_INCLUDED

#include <boost/predef/architecture.h>
#include <boost/simd/sdk/predef.hpp>

#include <boost/simd/arch/power/qpx/spec.hpp>
#include <boost/simd/arch/power/vsx/spec.hpp>
#include <boost/simd/arch/power/vmx/spec.hpp>

// Defines register count macros for POWERPC CPUs
#if BOOST_HW_SIMD_PPC
  #if BOOST_HW_SIMD_PPC == BOOST_HW_SIMD_PPC_VSX_VERSION
    #if !defined(BOOST_SIMD_VR_COUNT)
    #define BOOST_SIMD_VR_COUNT 64u
    #endif
  #else
    #if !defined(BOOST_SIMD_VR_COUNT)
    #define BOOST_SIMD_VR_COUNT 32u
    #endif
  #endif

  #if BOOST_HW_SIMD_PPC != BOOST_HW_SIMD_PPC_VSX_VERSION
    #if !defined(BOOST_SIMD_GPR_COUNT)
    #define BOOST_SIMD_GPR_COUNT  32u
    #endif
  #endif
#endif

#endif
