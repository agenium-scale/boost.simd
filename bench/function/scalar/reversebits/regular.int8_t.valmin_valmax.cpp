// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor reversebits in scalar mode for int8_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/reversebits.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/reversebits.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_reversebits, bs::reversebits);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_reversebits, int8_t>(bs::Valmin<int8_t>(), bs::Valmax<int8_t>());
}
