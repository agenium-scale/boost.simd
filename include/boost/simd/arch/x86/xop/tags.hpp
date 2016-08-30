//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for Intel X86 and AMD

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_XOP_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_XOP_TAGS_HPP_INCLUDED

#include <boost/simd/arch/x86/fma4/tags.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief AMD XOP SIMD architecture hierarchy tag

    This tag represent architectures implementing the AMD XOP SIMD instructions set.
  **/
  struct xop_ : fma4_
  {
    using parent = fma4_;

    xop_()
    {
      #if BOOST_ARCH_X86
      support =   detect_feature(11, 0x80000001, detail::ebx)
              &&  detect_feature(27, 0x80000001, detail::ecx);
      #else
      support = false;
      #endif
    }

    bool is_supported() const { return support; }

    private:
    bool support;
  };

  /*!
    @ingroup  group-api
    Global object for accessing XOP support informations
  **/
  static xop_ const xop = {};
} }

#endif
