// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/significants.hpp>
#include <boost/simd/function/simd/enumerate.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;
template < int N >
struct signif
{
  template<class T> T operator()(const T & a) const
  {
    using i_t = bd::as_integer_t<T>;
    return bs::significants(a, bs::enumerate<i_t>(0, N));
  }
};

DEFINE_SIMD_BENCH(simd_significantsp, signif< 1>());
DEFINE_SIMD_BENCH(simd_significantsn, signif<-1>());

DEFINE_BENCH_MAIN() {
  nsb::for_each<simd_significantsn, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<simd_significantsp, NS_BENCH_IEEE_TYPES>(-10, 10);
}
