//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for Intel X86 and AMD

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_TAGS_HPP_INCLUDED

#include <boost/simd/arch/x86/sse1/tags.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief Intel SSE2 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE2 SIMD instructions set.
  **/
  struct sse2_  : sse1_  { using parent = sse1_ ; };


} }

#endif
