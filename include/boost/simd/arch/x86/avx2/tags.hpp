//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for Intel X86 and AMD

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_TAGS_HPP_INCLUDED

#include <boost/simd/arch/x86/fma3/tags.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief Intel AVX2 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel AVX2 SIMD instructions set.
  **/
  struct avx2_  : fma3_
  {
    using parent = fma3_;

    avx2_() : support(detect()) {}

    bool is_supported() const { return support; }

    static bool detect()
    {
      #if BOOST_ARCH_X86
      return      detect_features( (1<< 5)|(1<< 3)|(1<< 8), 0x00000007, detail::ebx)
              &&  detect_features( (1<<27)|(1<<22)|(1<<12), 0x00000001, detail::ecx);
      #else
      return false;
      #endif
    }

    private:
    bool support;
  };

  /*!
    @ingroup  group-api
    Global object for accessing AVX2 support informations
  **/
  static avx2_ const avx2 = {};

} }

#endif
