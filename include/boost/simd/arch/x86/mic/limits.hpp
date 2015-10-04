//==================================================================================================
/*!
  @file

  Aggregate SIMD numerical and type limits for X86 MIC

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_MIC_LIMITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_MIC_LIMITS_HPP_INCLUDED

#include <boost/simd/arch/x86/tags.hpp>
#include <boost/simd/arch/common/limits.hpp>
#include <boost/dispatch/meta/generation/make_integer.hpp>

namespace boost { namespace simd
{
  template<> struct limits<boost::simd::mic_>
  {
    using parent = boost::simd::sse_;

    struct largest_integer
    {
      template<typename Sign> struct apply : boost::dispatch::make_integer<8,Sign> {};
    };

    struct smallest_integer
    {
      template<typename Sign> struct apply : boost::dispatch::make_integer<4,Sign> {};
    };

    using smallest_real = float;
    using largest_real  = double;

    enum { bits = 512, bytes = 64 };
  };
} }

#endif

