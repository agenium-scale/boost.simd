//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <simd_bench.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/raw.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_raw_trunc, bs::raw_(bs::trunc));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_raw_trunc, NS_BENCH_NUMERIC_TYPES>(-10, 10);
}
