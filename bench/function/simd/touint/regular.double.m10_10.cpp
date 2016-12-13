// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor touint in simd mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/touint.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_touint, bs::touint);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_touint, double>(-10, 10);
}
