//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for Intel X86 and AMD

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_TAGS_HPP_INCLUDED

#include <boost/simd/arch/common/tags.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief Intel SSE SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE SIMD instructions set.
  **/
  struct sse_   : simd_native_ { using parent = simd_native_; };

} }

#endif
