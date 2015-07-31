//==================================================================================================
/*!
  @file

  Defines the SSE specifications

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SPEC_HPP_INCLUDED

#include <boost/simd/sdk/predef.hpp>

#if (BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_SSE_VERSION)
#define BOOST_SIMD_BYTES              16
#define BOOST_SIMD_BITS               128
#define BOOST_SIMD_CARDINALS          (4)
#define BOOST_SIMD_TAG_SEQ            (::boost::simd::sse_)

#ifndef BOOST_SIMD_DEFAULT_EXTENSION
  #define BOOST_SIMD_DEFAULT_EXTENSION  ::boost::simd::sse_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::sse_

#include <xmmintrin.h>
#include <boost/simd/arch/x86/sse1/as_simd.hpp>

#endif
#endif
