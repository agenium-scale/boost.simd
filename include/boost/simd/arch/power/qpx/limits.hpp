//==================================================================================================
/*!
  @file

  Aggregate SIMD numerical and type limits for PPC QPX

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_QPX_LIMITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_QPX_LIMITS_HPP_INCLUDED

#include <boost/simd/arch/power/tags.hpp>
#include <boost/simd/arch/common/limits.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <cstdint>

namespace boost { namespace simd
{
  template<> struct limits<boost::simd::qpx_>
  {
    using parent = boost::simd::simd_;

    struct largest_integer
    {
      template<typename Sign> struct apply { using type = brigand::no_such_type_; };
    };

    struct smallest_integer
    {
      template<typename Sign> struct apply { using type = brigand::no_such_type_; };
    };

    using largest_real   = double;
    using smallest_real  = double;

    enum { bits = 256, bytes = 32 };
  };
} }

#endif

