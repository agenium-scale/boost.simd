//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for Intel X86 and AMD

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_FMA3_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_FMA3_TAGS_HPP_INCLUDED

#include <boost/simd/detail/predef.hpp>
#include <boost/simd/arch/x86/xop/tags.hpp>
#include <boost/simd/arch/x86/avx/tags.hpp>

namespace boost { namespace simd
{
#ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  struct fma3_ : xop_ { using parent = xop_; };
#else
  /*!
    @ingroup group-hierarchy
    @brief AMD FMA3 SIMD architecture hierarchy tag

    This tag represent architectures implementing the AMD FMA3 SIMD instructions set.
  **/
  struct fma3_ : avx_ { using parent = avx_; };
#endif

} }

#endif
