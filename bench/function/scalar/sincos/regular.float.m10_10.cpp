// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor sincos in scalar mode for float type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/sincos.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_sincos, bs::sincos);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_sincos, float>(-10, 10);
}
