// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor modf in scalar mode for std::uint16_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/modf.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_modf, bs::modf);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_modf, std::uint16_t>(0, 10);
}

