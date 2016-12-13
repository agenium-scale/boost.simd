// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor fnms in scalar mode for double type with pedantic_.
#include <simd_bench.hpp>
#include <boost/simd/function/fnms.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_fnms, bs::pedantic_(bs::fnms));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_fnms, double>(-10, 10, -10, 10, -10, 10);
}
