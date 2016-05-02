//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_IS_INCLUDED_C_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_IS_INCLUDED_C_HPP_INCLUDED

#include <boost/simd/function/scalar/is_included_c.hpp>
#include <boost/simd/arch/common/generic/function/autodispatcher.hpp>
#include <boost/simd/arch/common/simd/function/is_included_c.hpp>

#if defined(BOOST_HW_SIMD_X86)

#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE4_1_VERSION
#    include <boost/simd/arch/x86/sse4_1/simd/function/is_included_c.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX_VERSION
// #    include <boost/simd/arch/x86/avx/simd/function/is_included_c.hpp>
#  endif

#endif

#endif
