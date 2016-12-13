// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor is_not_infinite in scalar mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/is_not_infinite.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_is_not_infinite, bs::is_not_infinite);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_is_not_infinite, double>(-10, 10);
}
