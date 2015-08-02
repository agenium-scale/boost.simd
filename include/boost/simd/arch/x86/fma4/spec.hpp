//==================================================================================================
/*!
  @file

  Defines the FMA4 specifications

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_FMA4_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_FMA4_SPEC_HPP_INCLUDED

#include <boost/simd/sdk/predef.hpp>

#if BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_AMD_FMA4_VERSION

#ifndef BOOST_SIMD_DEFAULT_FAMILY
  #define BOOST_SIMD_DEFAULT_FAMILY  ::boost::simd::avx_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::fma4_

// FMA4 header not standardized
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#include <fma4intrin.h>
#endif

#include <boost/simd/arch/x86/sse2/as_simd.hpp>
#include <boost/simd/arch/x86/avx/as_simd.hpp>

#endif
#endif
