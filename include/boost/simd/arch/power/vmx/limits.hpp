//==================================================================================================
/*!
  @file

  Aggregate SIMD numerical and type limits for PPC VMX

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_VMX_LIMITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_VMX_LIMITS_HPP_INCLUDED

#include <boost/simd/arch/power/tags.hpp>
#include <boost/simd/arch/common/limits.hpp>
#include <boost/dispatch/meta/generation/make_integer.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <cstdint>

namespace boost { namespace simd
{
  template<> struct limits<boost::simd::vmx_>
  {
    template<typename Sign> using smallest_integer  = boost::dispatch::make_integer<1,Sign>;
    template<typename Sign> using largest_integer   = boost::dispatch::make_integer<4,Sign>;

    using largest_real   = float;
    using smallest_real  = float;

    enum { bits = 128, bytes = 16 };
  };
} }

#endif

