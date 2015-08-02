//==================================================================================================
/*!
  @file

  Aggregate SIMD numerical and type limits for ARM NEON

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_ARM_NEON_LIMITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_ARM_NEON_LIMITS_HPP_INCLUDED

#include <boost/simd/arch/arm/tags.hpp>
#include <boost/simd/arch/common/limits.hpp>
#include <boost/dispatch/meta/generation/make_integer.hpp>

namespace boost { namespace simd
{
  template<> struct limits<boost::simd::neon_>
  {
    using parent = boost::simd::neon64_;

    template<typename Sign> using smallest_integer  = boost::dispatch::make_integer<1,Sign>;
    template<typename Sign> using largest_integer   = boost::dispatch::make_integer<8,Sign>;

#ifdef __aarch64__
    using largest_real   = double;
#else
    using largest_real   = float;
#endif
    using smallest_real  = float;

    enum { bits = 128, bytes = 16 };
  };

  template<> struct limits<boost::simd::neon64_> : limits<boost::simd::neon_>
  {
    using parent = boost::simd::simd_;
  };
} }

#endif

