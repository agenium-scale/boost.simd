//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_2_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_2_TAGS_HPP_INCLUDED

#include <boost/simd/arch/x86/sse4_1/tags.hpp>
#include <boost/simd/detail/cpuid.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief Intel SSE 4.2 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE 4.2 SIMD instructions set.
  **/
  struct sse4_2_  : sse4_1_
  {
    using parent = sse4_1_;

    sse4_2_() : support(detect()) {}

    bool is_supported() const { return support; }

    static bool detect()
    {
      #if BOOST_ARCH_X86
      return detect_feature(20, 0x00000001, detail::ecx);
      #else
      return false;
      #endif
    }

    private:
    bool support;
  };

  /*!
    @ingroup  group-api
    Global object for accessing SSE4.2 support informations
  **/
  static sse4_2_ const sse4_2 = {};

} }

#endif
