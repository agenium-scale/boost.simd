//==================================================================================================
/*!
  @file

  Informations concerning x86 registers

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_REGISTER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_REGISTER_HPP_INCLUDED

#include <boost/predef/architecture.h>

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
