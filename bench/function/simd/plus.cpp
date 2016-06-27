// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/pack.hpp>
#include <cmath>

namespace nsb = ns::bench;

DEFINE_SIMD_BENCH(simd_plus, boost::simd::plus);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_plus, NS_BENCH_SIGNED_NUMERIC_TYPES>(-10, 10, -10, 10);
  nsb::for_each<simd_plus, NS_BENCH_UNSIGNED_NUMERIC_TYPES>(0, 10,  0,  10);
}
