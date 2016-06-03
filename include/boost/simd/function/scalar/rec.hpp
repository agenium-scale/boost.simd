//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SCALAR_REC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SCALAR_REC_HPP_INCLUDED

#include <boost/simd/function/definition/rec.hpp>
#include <boost/simd/arch/common/scalar/function/rec.hpp>
#include <boost/simd/arch/common/generic/function/rec.hpp>

// SSE scalar version of raw_rec
#if defined(BOOST_HW_SIMD_X86)
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE_VERSION
#    include <boost/simd/arch/x86/sse1/scalar/function/rec.hpp>
#  endif
#endif

#endif
