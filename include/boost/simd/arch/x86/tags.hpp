//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for Intel X86 and AMD

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_TAGS_HPP_INCLUDED

#include <boost/predef/hardware/simd.h>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief Intel SSE SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE SIMD instructions set.
  **/
  struct sse_   : simd_ { using parent = simd_; };

  /*!
    @ingroup group-hierarchy
    @brief Intel SSE2 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE2 SIMD instructions set.
  **/
  struct sse2_  : sse_  { using parent = sse_ ; };

  /*!
    @ingroup group-hierarchy
    @brief Intel SSE3 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE3 SIMD instructions set.
  **/
  struct sse3_  : sse2_ { using parent = sse2_; };

  /*!
    @ingroup group-hierarchy
    @brief Intel Supplemental SSE3 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel Supplemental SSE3 SIMD instructions set.
  **/
  struct ssse3_ : sse3_  { using parent = sse3_;  };

#ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  /*!
    @ingroup group-hierarchy
    @brief AMD SSE 4A SIMD architecture hierarchy tag

    This tag represent architectures implementing the AMD SSE 4A SIMD instructions set.
  **/
  struct sse4a_ : ssse3_ { using parent = ssse3_; };

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

  /*!
    @ingroup group-hierarchy
    @brief Intel SSE 4.2 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel SSE 4.2 SIMD instructions set.
  **/
  struct sse4_2_  : sse4_1_ { using parent = sse4_1_; };

  /*!
    @ingroup group-hierarchy
    @brief Intel AVX SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel AVX SIMD instructions set.
  **/
  struct avx_     : sse4_2_ { using parent = sse4_2_; };

#ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  /*!
    @ingroup group-hierarchy
    @brief Intel FMA4 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel FMA4 SIMD instructions set.
  **/
  struct fma4_    : avx_    { using parent = avx_ ;   };

  /*!
    @ingroup group-hierarchy
    @brief AMD XOP SIMD architecture hierarchy tag

    This tag represent architectures implementing the AMD XOP SIMD instructions set.
  **/
  struct xop_     : fma4_   { using parent = fma4_;   };
#endif

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

  /*!
    @ingroup group-hierarchy
    @brief Intel AVX2 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel AVX2 SIMD instructions set.
  **/
  struct avx2_  : fma3_ { using parent = fma3_; };

  /*!
    @ingroup group-hierarchy
    @brief Intel MIC SIMD architecture hierarchy tag

    This tag represent architectures implementing the Intel MIC SIMD instructions set.
  **/
  struct mic_   : sse2_ { using parent = sse2_; };
} }

#endif
