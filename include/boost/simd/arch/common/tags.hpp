//==================================================================================================
/*!
  @file

  Aggregates SIMD extension tags for common cases

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_TAGS_HPP_INCLUDED

#include <boost/dispatch/hierarchy/cpu.hpp>
#include <cstddef>

namespace boost { namespace simd
{
  /*!
    @ingroup group-hierarchy
    @brief Common SIMD architecture hierarchy tag

    This tag represent any architecture providing at least one flavor of SIMD instruction set.
  **/
  struct simd_ : boost::dispatch::cpu_
  {
    using parent = boost::dispatch::cpu_;
  };

  /*!
    @ingroup group-hierarchy
    @brief Emulated SIMD architecture hierarchy tag

    This tag represent any architecture requiring some SIMD register to be emulated as a small
    array of scalars. This is often the case when dealing with very small packs of data.
  **/
  template<std::size_t N> struct simd_emulation_ : boost::simd::simd_
  {
    using parent = boost::simd::simd_;
    using type = simd_emulation_;
  };

  /*!
    @ingroup group-hierarchy
    @brief Aggregated SIMD architecture hierarchy tag

    This tag represent any architecture requiring some SIMD register to be emulated as a tuple
    of smaller SIMD registers. This is often the case when dealing with very large packs of data.
  **/
  template<std::size_t N> struct simd_aggregation_ : boost::simd::simd_
  {
    using parent = boost::simd::simd_;
    using type = simd_aggregation_;
  };
} }

#endif
