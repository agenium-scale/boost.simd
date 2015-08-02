//==================================================================================================
/*!
  @file

  Defines the PPC QPX specifications

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_QPX_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_QPX_SPEC_HPP_INCLUDED

#include <boost/simd/sdk/predef.hpp>

#if BOOST_HW_SIMD_PPC == BOOST_HW_SIMD_PPC_QPX_VERSION

#ifndef BOOST_SIMD_DEFAULT_FAMILY
  #define BOOST_SIMD_DEFAULT_FAMILY  ::boost::simd::qpx_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::qpx_

// No Denormals on QPX familly
#ifndef BOOST_SIMD_NO_DENORMALS
  #define BOOST_SIMD_NO_DENORMALS
#endif

#include <boost/simd/arch/power/qpx/as_simd.hpp>

#endif
#endif
