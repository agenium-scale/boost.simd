//==================================================================================================
/*!
  @file

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
  /*!
    @ingroup group-hierarchy
    @brief Intel SSE 4.1 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE 4.1 SIMD instructions set.
  **/
#ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
    struct  sse4_1_ : sse4a_
    {
      using parent = sse4a_;
#else
    struct  sse4_1_ : ssse3_
    {
      using parent = ssse3_;
#endif

    sse4_1_() : support(detect()) {}

    bool is_supported() const { return support; }

    static bool detect()
    {
      #if BOOST_ARCH_X86
      return detect_feature(19, 0x00000001, detail::ecx);
      #else
      return false;
      #endif
    }

    private:
    bool support;
  };

  /*!
    @ingroup  group-api
    Global object for accessing SSE4.1 support informations
  **/
  static sse4_1_ const sse4_1 = {};

} }

#endif
