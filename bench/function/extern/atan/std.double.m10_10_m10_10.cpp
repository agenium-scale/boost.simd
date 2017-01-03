// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor atan in extern mode for double type with std_.
#include <simd_bench.hpp>
#include <boost/simd/function/atan.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_EXTERN_BENCH(extern_atan, bs::std_(bs::atan));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<extern_atan, double>(-10, 10,-10, 10);
}
