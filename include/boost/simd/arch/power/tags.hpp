//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for PowerPC

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_TAGS_HPP_INCLUDED

#include <boost/simd/arch/common/tags.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief PowerPC VMX SIMD architecture hierarchy tag

    This tag represent architectures implementing the VMX SIMD instructions set.
  **/
  struct vmx_ : simd_ { using parent = simd_; };

  /*!
    @ingroup group-hierarchy
    @brief PowerPC VSX SIMD architecture hierarchy tag

    This tag represent architectures implementing the VSX SIMD instructions set.
  **/
  struct vsx_ : vmx_  { using parent = vmx_; };

  /*!
    @ingroup group-hierarchy
    @brief PowerPC QPX SIMD architecture hierarchy tag

    This tag represent architectures implementing the QPX SIMD instructions set.
  **/
  struct qpx_ : simd_ { using parent = simd_; };
} }

#endif
