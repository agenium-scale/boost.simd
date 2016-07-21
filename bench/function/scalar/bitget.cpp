// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/bitget.hpp>
#include <boost/simd/function/simd/enumerate.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

struct bitg
{
  template<class T> T operator()(const T & a) const
  {
    using i_t = bd::as_integer_t<T>;
    return bs::bitset(a, bs::enumerate<i_t>());
  }
};

DEFINE_SCALAR_BENCH(scalar_bitget, bitg());
DEFINE_BENCH_MAIN() {
  nsb::for_each<scalar_bitget, NS_BENCH_NUMERIC_TYPES>(-10, 10);
}
