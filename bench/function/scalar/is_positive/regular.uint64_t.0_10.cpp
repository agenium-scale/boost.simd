// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor is_positive in scalar mode for std::uint64_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/is_positive.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_is_positive, bs::is_positive);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_is_positive, std::uint64_t>(0, 10);
}

