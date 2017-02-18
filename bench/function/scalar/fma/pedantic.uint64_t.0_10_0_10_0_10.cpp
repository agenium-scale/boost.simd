// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor fma in scalar mode for std::uint64_t type with pedantic_.
#include <simd_bench.hpp>
#include <boost/simd/function/fma.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_fma, bs::pedantic_(bs::fma));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_fma, std::uint64_t>(0, 10, 0, 10, 0, 10);
}

