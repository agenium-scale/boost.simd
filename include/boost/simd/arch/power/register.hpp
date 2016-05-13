//==================================================================================================
/*!
  @file

  Informations concerning PowerPC registers

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_REGISTER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_REGISTER_HPP_INCLUDED

#include <boost/predef/architecture.h>

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
