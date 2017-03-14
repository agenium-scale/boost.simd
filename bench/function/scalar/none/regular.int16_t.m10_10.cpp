// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor none in scalar mode for std::int16_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/none.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_BENCH_MAIN()
{
  using T = std::int16_t;
  run<T>(bs::none, nsbg::rand<T>(-10, 10));
}

