// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor clamp in simd mode for uint32_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/clamp.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_BENCH_MAIN()
{
  using T = bs::pack<std::uint32_t>;
  run<T>(bs::clamp, nsbg::rand<T>(0, 100), nsbg::rand<T>(0, 100), nsbg::rand<T>(0, 100));
}
