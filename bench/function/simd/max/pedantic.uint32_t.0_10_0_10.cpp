// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor max in simd mode for std::uint32_t type with pedantic_.
#include <simd_bench.hpp>
#include <boost/simd/function/max.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_BENCH_MAIN()
{
  using T = bs::pack<std::uint32_t>;
  run<T>(bs::pedantic_(bs::max), nsbg::rand<T>(-10, 10), nsbg::rand<T>(-10, 10));
}

