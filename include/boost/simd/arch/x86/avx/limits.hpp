//==================================================================================================
/*!
  @file

  Aggregate SIMD numerical and type limits for X86 AVX

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_LIMITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_LIMITS_HPP_INCLUDED

#include <boost/simd/arch/x86/tags.hpp>
#include <boost/simd/arch/common/limits.hpp>

namespace boost { namespace simd
{
  template<> struct limits<boost::simd::avx_>
  {
    template<typename Sign> using smallest_integer  = boost::dispatch::make_integer<1,Sign>;
    template<typename Sign> using largest_integer   = boost::dispatch::make_integer<8,Sign>;

    using smallest_real = float;
    using largest_real  = double;

    enum { bits = 256, bytes = 32 };
  };
} }

#endif

