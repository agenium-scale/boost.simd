//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for ARM

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_ARM_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_ARM_TAGS_HPP_INCLUDED

#include <boost/simd/arch/common/tags.hpp>

namespace boost { namespace simd
{
 /*!
    @ingroup group-hierarchy
    @brief ARM Neon64 SIMD architecture hierarchy tag

    This tag represent architectures implementing the Neon64 SIMD instructions set.
  **/
  struct neon64_ : simd_ { using parent = simd_; };

 /*!
    @ingroup group-hierarchy
    @brief ARM Neon SIMD architecture hierarchy tag

    This tag represent architectures implementing the Neon SIMD instructions set.
  **/
  struct neon_ : simd_ { using parent = simd_; };
} }

#endif
