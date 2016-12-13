// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor multiplies in scalar mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/multiplies.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_multiplies, bs::multiplies);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_multiplies, double>(-10, 10,-10, 10);
}
