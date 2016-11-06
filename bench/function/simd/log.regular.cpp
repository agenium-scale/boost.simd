// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------
#define BOOST_SIMD_NO_DENORMALS
#define BOOST_SIMD_NO_INVALIDS
#include <simd_bench.hpp>
#include <boost/simd/function/simd/log.hpp>
#include <boost/simd/pack.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_log, bs::log);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_log, NS_BENCH_IEEE_TYPES>(0, 1000);
}
