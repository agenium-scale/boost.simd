//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/std.hpp>
#include <simd_bench.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_std_ceil, bs::std_(bs::ceil));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_std_ceil, NS_BENCH_NUMERIC_TYPES>(-10, 10);
}
