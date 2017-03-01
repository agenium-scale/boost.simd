// -------------------------------------------------------------------------------------------------
//                              Copyright 2017 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor unary_plus in simd mode for std::uint32_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/unary_plus.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_unary_plus, bs::unary_plus);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_unary_plus, std::uint32_t>(0, 10);
}

