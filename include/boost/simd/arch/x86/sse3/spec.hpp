//==================================================================================================
/*!
  @file

  Defines the SSE3 specifications

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE3_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE3_SPEC_HPP_INCLUDED

#include <boost/predef/hardware/simd.h>

#if BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_SSE3_VERSION

#define BOOST_SIMD_BYTES              16
#define BOOST_SIMD_BITS               128
#define BOOST_SIMD_CARDINALS          (2)(4)(8)(16)
#define BOOST_SIMD_TAG_SEQ            (::boost::simd::sse_)

#ifndef BOOST_SIMD_DEFAULT_EXTENSION
  #define BOOST_SIMD_DEFAULT_EXTENSION  ::boost::simd::sse_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::sse3_

#include <pmmintrin.h>
#include <boost/simd/arch/x86/sse2/detail/as_simd.hpp>

#endif
#endif
