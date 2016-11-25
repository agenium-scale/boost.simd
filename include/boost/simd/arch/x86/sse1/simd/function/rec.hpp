//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/arch/x86/sse1/simd/function/rec_raw.hpp>
#include <boost/simd/arch/x86/sse1/simd/function/rec_fast.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  // No better version of rec than division

} } }

#endif
