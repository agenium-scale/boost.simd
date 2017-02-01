// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor pow_abs in simd mode for double type with raw_.
#include <simd_bench.hpp>
#include <boost/simd/function/pow_abs.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_pow_abs, bs::raw_(bs::pow_abs));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_pow_abs, double>(-10, 10,-10, 10);
}
