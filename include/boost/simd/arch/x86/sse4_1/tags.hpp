//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for Intel X86 and AMD

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_TAGS_HPP_INCLUDED

#include <boost/simd/detail/predef.hpp>
#include <boost/simd/arch/x86/ssse3/tags.hpp>
#include <boost/simd/arch/x86/sse4a/tags.hpp>

namespace boost { namespace simd
{
#ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  /*!
    @ingroup group-hierarchy
    @brief Intel SSE 4.1 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE 4.1 SIMD instructions set.
  **/
  struct sse4_1_  : sse4a_  { using parent = sse4a_;  };
#else
  /*!
    @ingroup group-hierarchy
    @brief Intel SSE 4.1 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE 4.1 SIMD instructions set.
  **/
  struct sse4_1_  : ssse3_  { using parent = ssse3_;  };
#endif

} }

#endif
