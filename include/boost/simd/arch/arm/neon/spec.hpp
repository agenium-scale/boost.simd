//==================================================================================================
/*!
  @file

  Defines the ARM NEON specifications

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_ARM_NEON_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_ARM_NEON_SPEC_HPP_INCLUDED

#include <boost/predef/hardware/simd.h>

#if BOOST_HW_SIMD_ARM == BOOST_HW_SIMD_ARM_NEON_VERSION

#define BOOST_SIMD_BYTES              16
#define BOOST_SIMD_BITS               128
#define BOOST_SIMD_CARDINALS          (2)(4)(8)(16)
#define BOOST_SIMD_TAG_SEQ            (::boost::simd::neon64_)(::boost::simd::neon_)

#ifndef BOOST_SIMD_DEFAULT_EXTENSION
  #define BOOST_SIMD_DEFAULT_EXTENSION  ::boost::simd::neon_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::neon_

#include <arm_neon.h>
#include <boost/simd/arch/arm/neon/as_simd.hpp>

#endif
#endif
