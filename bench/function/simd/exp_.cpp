// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <ns.bench.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/exp.hpp>
#include <cmath>

namespace bs = boost::simd;
namespace nsb = ns::bench;

DEFINE_SIMD_BENCH(simd_exp, bs::exp);

DEFINE_BENCH_MAIN() {
  nsb::for_each<simd_exp, NS_BENCH_NUMERIC_TYPES>(-10, 10);
}

