//==================================================================================================
/*!
  @file

  Gather informations for ARM SIMD extensions

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_ARM_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_ARM_SPEC_HPP_INCLUDED

#include <boost/predef/architecture.h>
#include <boost/simd/detail/predef.hpp>

#include <boost/simd/arch/arm/neon/spec.hpp>

// Defines register count macros for ARM CPUs
#if BOOST_HW_SIMD_ARM
  #if BOOST_HW_SIMD_ARM == BOOST_HW_SIMD_PPC_VSX_VERSION
    #if !defined(BOOST_SIMD_VR_COUNT)
    #define BOOST_SIMD_VR_COUNT 16u
    #endif
  #endif

  #if !defined(BOOST_SIMD_GPR_COUNT)
  #define BOOST_SIMD_GPR_COUNT  16u
  #endif

#endif

#endif
