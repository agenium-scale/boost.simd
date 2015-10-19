//==================================================================================================
/*!
  @file

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPES_HPP_INCLUDED
#define BOOST_SIMD_TYPES_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <cstddef>

namespace boost { namespace simd
{
  using brigand::real_;
  using brigand::double_;
  using brigand::single_;

  template<typename RealType, std::intmax_t N, std::intmax_t D = 1>
  struct ratio
  {};

  template<std::intmax_t N, std::intmax_t D> using single_ratio = ratio<float,N,D>;

  template<std::intmax_t N, std::intmax_t D> using double_ratio = ratio<double,N,D>;
} }

#endif
