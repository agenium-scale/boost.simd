//==================================================================================================
/*!
  @file

  Useful tags forward declarations and aliases

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_DETAIL_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_DETAIL_TAGS_HPP_INCLUDED

namespace boost { namespace simd { namespace tag
{
  struct exp_;
  struct exp2_;
  struct exp10_;
  struct log_;
  struct log2_;
  struct log10_;

  using  not_simd_type = std::integral_constant<bool, false>;
  using  simd_type = std::integral_constant<bool, true>;
} } }

#endif
