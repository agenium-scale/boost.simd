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
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

struct bitg
{
  template<class T>  bd::as_integer_t<T, unsigned> operator()(const T & a) const
  {
    using i_t = bd::as_integer_t<T>;
    return bs::bitget(a, bs::enumerate<i_t>());
  }
};

DEFINE_SIMD_BENCH(simd_bitget, bitg());
DEFINE_BENCH_MAIN() {
  nsb::for_each<simd_bitget, NS_BENCH_INTEGRAL_TYPES>(-10, 10);
}
