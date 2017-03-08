// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor is_not_equal_with_equal_nans in simd mode for std::int8_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/is_not_equal_with_equal_nans.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_is_not_equal_with_equal_nans, bs::is_not_equal_with_equal_nans);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_is_not_equal_with_equal_nans, std::int8_t>(-10, 10, -10, 10);
}

