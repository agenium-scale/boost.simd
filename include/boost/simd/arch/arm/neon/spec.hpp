//==================================================================================================
/*!
  @file

  Defines the ARM NEON specifications

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_ARM_NEON_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_ARM_NEON_SPEC_HPP_INCLUDED

#include <boost/simd/sdk/predef.hpp>

#if BOOST_HW_SIMD_ARM == BOOST_HW_SIMD_ARM_NEON_VERSION

#ifndef BOOST_SIMD_DEFAULT_FAMILY
  #define BOOST_SIMD_DEFAULT_FAMILY  ::boost::simd::neon_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::neon_

#include <arm_neon.h>
#include <boost/simd/arch/arm/neon/as_simd.hpp>

#endif
#endif
