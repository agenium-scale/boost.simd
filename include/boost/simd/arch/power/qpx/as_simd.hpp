//==================================================================================================
/*!
  @file

  Defines the as_simd metafunction for QPX like extensions

  @copyright 2009 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_POWER_QPX_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_POWER_QPX_AS_SIMD_HPP_INCLUDED

#include <boost/simd/arch/common/simd/as_simd.hpp>
#include <boost/dispatch/meta/introspection/is_natural.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd
{
  template<typename T> struct logical;

  namespace ext
  {
    template<> struct as_simd<double, boost::simd::qpx_>
    {
      using type = vector4double;
    };

    template<typename T>
    struct as_simd<logical<T>, boost::simd::qpx_>
    {
      using type = vector4double;
    };
  }
} }

#endif
