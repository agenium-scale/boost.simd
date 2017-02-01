// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor logical_notand in simd mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/logical_notand.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_logical_notand, bs::logical_notand);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_logical_notand, double>(-10, 10,-10, 10);
}
