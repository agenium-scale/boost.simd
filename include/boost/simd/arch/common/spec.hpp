//==================================================================================================
/*!
  @file

  Defines the common CPU specifications

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SPEC_HPP_INCLUDED

#if !defined(BOOST_HW_SIMD_AVAILABLE)

#ifndef BOOST_SIMD_DEFAULT_FAMILY
#define BOOST_SIMD_DEFAULT_FAMILY ::boost::simd::simd_emulation_
#endif

#define BOOST_SIMD_DEFAULT_SITE ::boost::dispatch::cpu_

#include <boost/simd/arch/common/simd/as_simd.hpp>

#endif
#endif
