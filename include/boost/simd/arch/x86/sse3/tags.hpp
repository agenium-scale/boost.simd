//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE3_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE3_TAGS_HPP_INCLUDED

#include <boost/simd/arch/x86/sse2/tags.hpp>
#include <boost/simd/detail/cpuid.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief Intel SSE3 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE3 SIMD instructions set.
  **/
  struct sse3_  : sse2_
  {
    using parent = sse2_;

    sse3_() : support(detect()) {}

    bool is_supported() const { return support; }

    static bool detect()
    {
      #if BOOST_ARCH_X86
      return detect_feature(0, 0x00000001, detail::ecx);
      #else
      return false;
      #endif
    }

    private:
    bool support;
  };

  /*!
    @ingroup  group-api
    Global object for accessing SSE3 support informations
  **/
  static sse3_ const sse3 = {};

} }

#endif
