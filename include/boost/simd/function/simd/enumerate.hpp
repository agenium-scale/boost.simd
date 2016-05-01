//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_ENUMERATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_ENUMERATE_HPP_INCLUDED

#include <boost/simd/function/scalar/enumerate.hpp>
#include <boost/simd/arch/common/simd/function/enumerate.hpp>

#if defined(BOOST_HW_SIMD_PPC)

#  if BOOST_HW_SIMD_PPC >= BOOST_HW_SIMD_PPC_VMX_VERSION
// #    include <boost/simd/arch/power/vmx/simd/function/enumerate.hpp>
#  endif

#endif

#endif
