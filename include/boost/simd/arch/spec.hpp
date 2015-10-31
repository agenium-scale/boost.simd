//==================================================================================================
/*!
  @file

  Aggregate SIMD specifications definitions

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_SPEC_HPP_INCLUDED

#if !defined(BOOST_SIMD_NO_SIMD)
#include <boost/simd/arch/power/spec.hpp>
#include <boost/simd/arch/arm/spec.hpp>
#include <boost/simd/arch/x86/spec.hpp>
#endif

#include <boost/simd/arch/common/spec.hpp>

#if defined(BOOST_HW_SIMD_AVAILABLE)
#define BOOST_SIMD_DETECTED
#endif

#endif

