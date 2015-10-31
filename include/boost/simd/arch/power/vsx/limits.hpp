//==================================================================================================
/*!
  @file

  Aggregate SIMD numerical and type limits for PPC VSX

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VSX_LIMITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VSX_LIMITS_HPP_INCLUDED

#include <boost/simd/arch/power/tags.hpp>
#include <boost/simd/arch/common/limits.hpp>
#include <boost/simd/arch/power/vmx/limits.hpp>
#include <boost/simd/arch/x86/sse2/limits.hpp>

namespace boost { namespace simd
{
  template<> struct limits<boost::simd::vsx_> : limits<boost::simd::sse2_> {};
} }

#endif

