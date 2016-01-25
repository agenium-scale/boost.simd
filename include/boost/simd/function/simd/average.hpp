//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_AVERAGE_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_AVERAGE_INCLUDED

#include <boost/simd/function/scalar/average.hpp>
#include <boost/simd/arch/common/generic/function/average.hpp>

#if defined(BOOST_HW_SIMD_ARM)

#  if BOOST_HW_SIMD_ARM >= BOOST_HW_SIMD_ARM_NEON_VERSION
#    include <boost/simd/arch/arm/neon/simd/function/average.hpp>
#  endif
#  if BOOST_HW_SIMD_ARM >= BOOST_HW_SIMD_ARM_NEON64_VERSION
#    include <boost/simd/arch/arm/neon64/simd/function/average.hpp>
#  endif

#endif

#endif
