//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for Intel X86 and AMD

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_FMA4_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_FMA4_TAGS_HPP_INCLUDED

#include <boost/simd/arch/x86/avx/tags.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief Intel FMA4 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel FMA4 SIMD instructions set.
  **/
  struct fma4_    : avx_
  {
    using parent = avx_ ;

    fma4_() : support(detect()) {}

    bool is_supported() const { return support; }

    static bool detect()
    {
      #if BOOST_ARCH_X86
      return      detect_feature(16, 0x80000001, detail::ecx)
              &&  detect_feature(27, 0x80000001, detail::ecx);
      #else
      return false;
      #endif
    }

    private:
    bool support;
  };

  /*!
    @ingroup  group-api
    Global object for accessing FMA4 support informations
  **/
  static fma4_ const fma4 = {};

} }

#endif
