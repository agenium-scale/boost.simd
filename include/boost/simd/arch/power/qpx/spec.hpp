//==================================================================================================
/*!
  @file

  Defines the PPC QPX specifications

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_QPX_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_QPX_SPEC_HPP_INCLUDED

#include <boost/predef/hardware/simd.h>

#if BOOST_HW_SIMD_PPC == BOOST_HW_SIMD_PPC_QPX_VERSION

#define BOOST_SIMD_BYTES              32
#define BOOST_SIMD_BITS               256
#define BOOST_SIMD_CARDINALS          (4)
#define BOOST_SIMD_TAG_SEQ            (::boost::simd::qpx_)

#ifndef BOOST_SIMD_DEFAULT_EXTENSION
  #define BOOST_SIMD_DEFAULT_EXTENSION  ::boost::simd::qpx_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::qpx_

// No Denormals on QPX familly
#ifndef BOOST_SIMD_NO_DENORMALS
  #define BOOST_SIMD_NO_DENORMALS
#endif

#include <boost/simd/arch/power/qpx/as_simd.hpp>

#endif
#endif
