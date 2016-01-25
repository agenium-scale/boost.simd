//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_TOINTS_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_TOINTS_INCLUDED

#include <boost/simd/function/scalar/toints.hpp>
#include <boost/simd/arch/common/simd/function/toints.hpp>

#if defined(BOOST_HW_SIMD_PPC)

#  if BOOST_HW_SIMD_PPC >= BOOST_HW_SIMD_PPC_VMX_VERSION
#    include <boost/simd/arch/power/vmx/simd/function/toints.hpp>
#  endif

#endif

#endif
