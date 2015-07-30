//==================================================================================================
/*!
  @file

  Defines the MIC specifications

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_MIC_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_MIC_SPEC_HPP_INCLUDED

#include <boost/predef/hardware/simd.h>

#if BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_MIC_VERSION

#define BOOST_SIMD_BYTES              64
#define BOOST_SIMD_BITS               512
#define BOOST_SIMD_CARDINALS          (8)(16)
#define BOOST_SIMD_TAG_SEQ            (::boost::simd::mic_)(::boost::simd::sse_)

#ifndef BOOST_SIMD_DEFAULT_EXTENSION
  #define BOOST_SIMD_DEFAULT_EXTENSION  ::boost::simd::mic_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::mic_

#include <immintrin.h>
#include <boost/simd/arch/x86/mic/as_simd.hpp>

#endif
#endif
