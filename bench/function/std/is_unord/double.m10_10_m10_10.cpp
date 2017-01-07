// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor is_unord in std mode for double type with std_.
#include <simd_bench.hpp>
#include <boost/simd/function/is_unord.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(std_is_unord, bs::std_(bs::is_unord));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<std_is_unord, double>(-10, 10, -10, 10);
}
