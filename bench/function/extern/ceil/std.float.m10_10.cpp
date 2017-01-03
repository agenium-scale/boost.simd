// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor ceil in extern mode for float type with std_.
#include <simd_bench.hpp>
#include <boost/simd/function/ceil.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_EXTERN_BENCH(extern_ceil, bs::std_(bs::ceil));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<extern_ceil, float>(-10, 10);
}
