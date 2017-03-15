// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor fma in simd mode for std::uint16_t type with pedantic_.
#include <simd_bench.hpp>
#include <boost/simd/function/fma.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_BENCH_MAIN()
{
  using T = bs::pack<std::uint16_t>;
  run<T>(bs::pedantic_(bs::fma), nsbg::rand<T>(0, 10), nsbg::rand<T>(0, 10), nsbg::rand<T>(0, 10));
}

