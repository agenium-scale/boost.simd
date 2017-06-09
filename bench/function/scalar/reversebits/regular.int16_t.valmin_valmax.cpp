// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor reversebits in scalar mode for int16_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/reversebits.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
DEFINE_BENCH_MAIN()
{
  using T = int16_t;
  using U = T;
  run<T>(bs::reversebits, nsbg::rand<T>(bs::Valmin<U>(), bs::Valmax<U>()));
}
