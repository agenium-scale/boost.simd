// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor compare_greater_equal in simd mode for float type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/compare_greater_equal.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_compare_greater_equal, bs::compare_greater_equal);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_compare_greater_equal, float>(-10, 10,-10, 10);
}
